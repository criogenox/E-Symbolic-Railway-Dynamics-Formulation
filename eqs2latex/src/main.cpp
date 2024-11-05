#include <iostream>
#include "tex.h"

int main() {
    // Input expression
    const auto input = "-16*K3*a^2*b^3-20-5*d2_psi1 == 0";

    // Processing expression to LaTeX
    std::cout << "Original string:  " << input << std::endl;
    std::string latexOutput = processExpression(input);
    std::cout << "Processed expression:  " << latexOutput << std::endl;

    // Split the latexOutput into LHS & RHS
    const size_t equalPos = latexOutput.find('=');
    if (equalPos == std::string::npos) {
        std::cerr << "Error: No equal sign found in output." << std::endl;
        return 1; // Early exit on error
    }

    const auto eqLHS = latexOutput.substr(0, equalPos); // Removing "=0"
    const auto noRHS = latexOutput.substr(equalPos); // Preserving "=0" for reconstruction
    // It has no sense here the above line, but for future uses could be useful to have RHS

    std::cout << "Terms part:  " << eqLHS << std::endl;

    // Extract terms to perform sorting
    auto terms = extractTerms(eqLHS);
    for (const auto &term: terms) {
        std::cout << "Extracted term:  " << term << std::endl;
    }

    std::vector<std::string> sortedTerms = sortTerms(terms);
    for (const auto &sortedTerm: sortedTerms) {
        std::cout << "Sorted term:  " << sortedTerm << std::endl;
    }

    // Output string reconstruction
    std::string output;
    output.append(reconstructOutput(sortedTerms)).append(" ").append(noRHS);
    std::cout << "Reconstructed output:  " << output << std::endl;

    // Remove '*' from the output
    std::erase(output, '*');
    std::cout << "Final output (no '*'):  " << output << std::endl;

    return 0;
}
