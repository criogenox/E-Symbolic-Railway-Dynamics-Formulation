#include <iostream>
#include "tex.h"

int main() {
    // Input expression
    const auto input =
            "4*C2*b*d_theta1-3*C153*d_phi1+7*a5^3*C3*d_phi1+C12*d_psi1-M1*axy^2*d2_theta1"
            "+a^2*C3*d_psi1+s*F10+c^2*am*C3*d_theta1-4*M2*b*d2_xi1-4*C*d_phi1+20*h"
            "+16*C7*d_psi1=0";

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

    std::cout << "Left-hand side:  " << eqLHS << std::endl;

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

    return 0;
}
