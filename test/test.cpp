#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TStack.h"
#include<vector>
#include "TPostfix.h"
#include<string>
using namespace std;
TEST(TestGroupName, test_to_postfix1) {
    string s = TPostfix::to_postfix("2+2");
    ASSERT_EQ(s, "22+");
}
TEST(TestGroupName, test_to_postfix2) {
    string s = TPostfix::to_postfix("2*2");
    ASSERT_EQ(s, "22*");
}
TEST(TestGroupName, test_to_postfix3) {
    string s = TPostfix::to_postfix("1+2*3");
    ASSERT_EQ(s, "123*+");
}
TEST(TestGroupName, test_to_postfix4) {
    string s = TPostfix::to_postfix("2*3+1");
    ASSERT_EQ(s, "23*1+");
}
TEST(TestGroupName, test_to_postfix5) {
    string s = TPostfix::to_postfix("2*(1+3)");
    ASSERT_EQ(s, "213+*");
}
TEST(TestGroupName, test_to_postfix6) {
    string s = TPostfix::to_postfix("(1+2)*3");
    ASSERT_EQ(s, "12+3*");
}
TEST(TestGroupName, postfix_solve1) {
    string s = TPostfix::to_postfix("2+2");
    ASSERT_EQ(TPostfix::postfix_solve(s), "4");
}
TEST(TestGroupName, postfix_solve2) {
    string s = TPostfix::to_postfix("2*2");
    ASSERT_EQ(TPostfix::postfix_solve(s), "4");
}
TEST(TestGroupName, postfix_solve3) {
    string s = TPostfix::to_postfix("1+2*3");
    ASSERT_EQ(TPostfix::postfix_solve(s), "7");
}
TEST(TestGroupName, postfix_solve4) {
    string s = TPostfix::to_postfix("2*3+1");
    ASSERT_EQ(TPostfix::postfix_solve(s), "7");
}
TEST(TestGroupName, postfix_solve5) {
    string s = TPostfix::to_postfix("2*(1+3)");
    ASSERT_EQ(TPostfix::postfix_solve(s), "8");
}
TEST(TestGroupName, postfix_solve6) {
    string s = TPostfix::to_postfix("(1+2)*3");
    ASSERT_EQ(TPostfix::postfix_solve(s), "9");
}