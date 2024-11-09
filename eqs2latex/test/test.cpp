#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "tex.h"

// Test for convertToLatex
TEST(ConvertToLatexTest, FullConversion) {
    EXPECT_EQ(convert("20*K2*axy^6*b^3-16+M4*d2_psi1 == 0"), R"(M_{4}\ddot{\psi}_{1}+20K_{2}a_{xy}^{6}b^{3}-16 =0)");
    EXPECT_EQ(convert("-5*K3*a^2*bz^10-8*d_psi1+s*F2==0"), R"(-8\dot{\psi}_{1}-5K_{3}a^{2}b_{z}^{10}+sF_{2} =0)");
}

// Test for splitTerms & individual LaTeX conversion
TEST(ProcessExpressionTest, HandleExpressions) {
    EXPECT_EQ(processExpression("b12 *C1* d_phi1 == 0"), "b_{12}*C_{1}*\\dot{\\phi}_{1}=0");
    EXPECT_EQ(processExpression("M2 *d2_phi1+ K2 * a^3*X ==0"), "M_{2}*\\ddot{\\phi}_{1}+K_{2}*a^{3}*X=0");
    EXPECT_EQ(processExpression("d_theta2 -c7^2*d_phi1== 0"), "\\dot{\\theta}_{2}-c_{7}^{2}*\\dot{\\phi}_{1}=0");
}

// Test for extractTerms
TEST(ExtractTermsTest, FullExtraction) {
    const std::vector<std::string> expected = {"C1*d\\phi1", "-M2*d2\\phi1", "K3*X2"};
    EXPECT_EQ(extractTerms("C1*d\\phi1-M2*d2\\phi1+K3*X2"), expected);
}

// Test for sortTerms
TEST(SortTermsTest, OrderSorting) {
    const std::vector<std::string> terms = {"s*F_{2}", "-16*K_{3}*a^{2}*b^{3}", "-20*h", "-5*\\ddot{\\psi}_{1}"};
    const std::vector<std::string> sorted = sortTerms(terms);
    EXPECT_EQ(sorted[0], "-5*\\ddot{\\psi}_{1}");
    EXPECT_EQ(sorted[1], "-16*K_{3}*a^{2}*b^{3}");
    EXPECT_EQ(sorted[2], "-20*h");
    EXPECT_EQ(sorted[3], "s*F_{2}");
}

// Test for reconstructOutput
TEST(ReconstructOutputTest, TermsReconstruction) {
    const std::vector<std::string> sortedTerms = {"-5*\\ddot{\\psi}_{1}", "-16*K_{3}*a^{2}*b^{3}", "-20"};
    EXPECT_EQ(reconstructOutput(sortedTerms), R"(-5\ddot{\psi}_{1}-16K_{3}a^{2}b^{3}-20)");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
