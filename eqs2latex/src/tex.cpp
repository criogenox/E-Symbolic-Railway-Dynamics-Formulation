#include "tex.h"

void eraseEmptyBraces(std::string &output) {
    // Substring to erase
    const std::string toErase = "_{}";
    size_t pos = 0;

    // Loop to find and erase all occurrences of the substring
    while ((pos = output.find(toErase, pos)) != std::string::npos) {
        output.erase(pos, toErase.length());
        // No need to increment pos, as the string has changed
    }
}

unsigned find1NumberPos(const std::string &str) {
    // Backward scan preventing undesirable front-numbers detection
    for (unsigned i = str.size(); i > 0; --i) {
        if (!isdigit(str[i - 1])) {
            return i - 1;
        }
    }
    return 0;
}

// LaTeX string conversion
std::string convertToLatex(const std::string &input) {
    std::string output;
    // Replace 1° & 2° order derivative operators
    if (input.starts_with("d2")) {
        output.append("\\ddot{");
    } else if (input.starts_with("d")) {
        output.append("\\dot{");
    }
    // Find underscore symbol indicating a special letter
    size_t letterStart = input.find('_');
    if (letterStart != std::string::npos) {
        size_t letterEnd = letterStart + 1;
        while (letterEnd < input.size() && (isalpha(input[letterEnd]) || input[letterEnd] == '{')) {
            letterEnd++;
        }
        output.append("\\").append(input, letterStart + 1, letterEnd - letterStart - 1);
    } else {
        // If no underscore found, look for "d2" or "d"
        if (input.starts_with("d2") || input.starts_with("d")) {
            const size_t start = input.starts_with("d2") ? 2 : 1;
            for (size_t i = start; i < input.size(); ++i) {
                if (isalpha(input[i])) {
                    output.append(1, input[i]);
                    break;
                }
            } // Check any other no-derivative variable
        } else if (!isdigit(input.front())) {
            output.append(1, input[0]);
            if (input.size() > 1) {
                output.append("_{");
                for (size_t i = 1; i < input.size(); ++i) {
                    if (input[i] == '^') {
                        output.append("}^{");
                    } else {
                        output.append(1, input[i]);
                    }
                }
            }
        } else {
            // Append numeric term/constant
            output.append(input);
        }
    }
    // Checking for numeric subscripts
    if (!input.empty() && isdigit(input.back()) && input.front() == 'd') {
        const unsigned index = find1NumberPos(input);
        output.append("}_{").append(input.substr(index + 1)).append("}");
    } else if (input.size() > 1 && !isdigit(input.front())) {
        output.append("}");
    }

    return output;
}

// Match any individual element (-|+|*|=|==|0 operators as delimiters)
std::vector<std::string> splitTerms(const std::string &expression) {
    std::vector<std::string> terms;
    const std::regex regex(R"((==)|(=)|(\*)|(\+)|(-)|([^ \*\=\+\-]+))");
    for (std::sregex_iterator it(expression.begin(), expression.end(), regex), end; it != end; ++it) {
        terms.push_back(it->str());
    }
    return terms;
}

std::string processExpression(const std::string &expression) {
    std::vector<std::string> terms = splitTerms(expression);
    std::string latexOutput;
    for (const std::string &term: terms) {
        if (term == "==") {
            latexOutput += "=";
        } else if (term == "+" || term == "-") {
            latexOutput += term;
        } else {
            latexOutput += convertToLatex(term);
        }
    }
    // Remove empty braces "_{}"
    eraseEmptyBraces(latexOutput);
    return latexOutput;
}

// Match equation terms (-|+ operators as delimiters)
std::vector<std::string> extractTerms(const std::string &input) {
    const std::regex termRegex(R"(([-]?[^+\-=]+))");
    std::vector<std::string> terms;
    for (std::sregex_iterator i(input.begin(), input.end(), termRegex), end; i != end; ++i) {
        terms.push_back(i->str());
    }
    return terms;
}

// Match the term's numeric subscript
int extractSubscript(const std::string &term) {
    std::smatch match;
    const std::regex endNumberRegex(R"((\d+)(?!.*\d))");
    return std::regex_search(term, match, endNumberRegex) ? std::stoi(match[1].str()) : -1;
}

// Sorting terms based on derivative order and numeric subscript
std::vector<std::string> sortTerms(const std::vector<std::string> &terms) {
    // Defining the sorting criteria
    auto sortingCriteria = [](const std::string &a, const std::string &b) {
        const int aOrder = (a.find("ddot") != std::string::npos)
                               ? 1
                               : (a.find("dot") != std::string::npos)
                                     ? 2
                                     : (a.find('K') != std::string::npos)
                                           ? 3
                                           : 4;

        const int bOrder = (b.find("ddot") != std::string::npos)
                               ? 1
                               : (b.find("dot") != std::string::npos)
                                     ? 2
                                     : (b.find('K') != std::string::npos)
                                           ? 3
                                           : 4;
        // Sort by derivative order
        if (aOrder != bOrder) return aOrder < bOrder;
        // Same order, sort by subscript (highest to lowest)
        return extractSubscript(a) > extractSubscript(b);
    };
    // Custom criteria call
    std::vector<std::string> sortedTerms = terms;
    std::ranges::sort(sortedTerms, sortingCriteria);
    return sortedTerms;
}

// Output string reconstruction
std::string reconstructOutput(const std::vector<std::string> &sortedTerms) {
    std::string output;
    for (const auto &term: sortedTerms) {
        if (!output.empty() && term[0] != '-') {
            output += "+";
        }
        output += term;
    }
    // Remove '*' from the output
    std::erase(output, '*');
    return output;
}

// Function call for Gtest
std::string convert(const std::string &input) {
    // Processing expression to LaTeX
    std::string latexOutput = processExpression(input);

    // Split the latexOutput into LHS & RHS
    const size_t equalPos = latexOutput.find('=');
    const auto eqLHS = latexOutput.substr(0, equalPos); // Removing "=0"
    const auto noRHS = latexOutput.substr(equalPos); // Preserving "=0" for reconstruction
    // It has no sense here the above line, but for future uses could be useful to have RHS

    // Extract terms to perform sorting
    const auto terms = extractTerms(eqLHS);
    std::vector<std::string> sortedTerms = sortTerms(terms);

    // Output string reconstruction
    std::string output;
    output.append(reconstructOutput(sortedTerms)).append(" ").append(noRHS);

    // Remove '*' and empty braces "_{}" from the output
    std::erase(output, '*');
    eraseEmptyBraces(output);

    return output;
}
