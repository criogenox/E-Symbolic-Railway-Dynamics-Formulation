#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "tex.h"

// Test for convertToLatex
TEST(ConvertToLatexTest, BasicConversions) {
    EXPECT_EQ(convert("-K3*a^2*b^3-16+d2_psi1 == 0"), R"(\ddot{\psi}_{1}-K_{3}a_{}^{2}b_{}^{3}-16 =0)");
    EXPECT_EQ(convert("-5*K3*a^2*b^3-16*d_psi1==0"), R"(-16\dot{\psi}_{1}-5K_{3}a_{}^{2}b_{}^{3} =0)");
}

// Test for processExpression
TEST(ProcessExpressionTest, HandleExpressions) {
    EXPECT_EQ(processExpression("C1 * d_phi1 == 0"), "C_{1}*\\dot{\\phi}_{1}=0");
    EXPECT_EQ(processExpression("M2 * d2_phi1 + K2 * X == 0"), "M_{2}*\\ddot{\\phi}_{1}+K_{2}*X=0");
    EXPECT_EQ(processExpression("d_theta2 - d_phi1 == 0"), "\\dot{\\theta}_{2}-\\dot{\\phi}_{1}=0");
}

// Test for extractTerms
TEST(ExtractTermsTest, BasicExtraction) {
    std::vector<std::string> expected = {"C1*d\\phi1", "M2*d2\\phi1"};
    EXPECT_EQ(extractTerms("C1*d\\phi1+M2*d2\\phi1"), expected);
}

// Test for sortTerms
TEST(SortTermsTest, BasicSorting) {
    std::vector<std::string> terms = {"-16*K_{3}*a_{}^{2}*b_{}^{3}", "-20", "-5*\\ddot{\\psi}_{1}"};
    std::vector<std::string> sorted = sortTerms(terms);
    EXPECT_EQ(sorted[0], "-5*\\ddot{\\psi}_{1}");
    EXPECT_EQ(sorted[1], "-16*K_{3}*a_{}^{2}*b_{}^{3}");
    EXPECT_EQ(sorted[2], "-20");
}

// Test for reconstructOutput
TEST(ReconstructOutputTest, BasicReconstruction) {
    std::vector<std::string> sortedTerms = {"-5*\\ddot{\\psi}_{1}", "-16*K_{3}*a_{}^{2}*b_{}^{3}", "-20"};
    EXPECT_EQ(reconstructOutput(sortedTerms), R"(-5*\ddot{\psi}_{1}-16*K_{3}*a_{}^{2}*b_{}^{3}-20)");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
