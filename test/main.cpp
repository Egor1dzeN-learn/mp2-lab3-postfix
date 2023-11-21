//
// Created by egorm on 27.10.2023.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include<stack>
#include "TPostfix.h"

using namespace std;

int main(int argc, char **argv) {
//    cout<< TPostfix::postfix_solve("22+2*")<<endl;
//    string s = TPostfix::to_postfix("2*(2+2)");
//    cout<<s;
//    TPostfix::postfix_solve(s);
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);
//
    return RUN_ALL_TESTS();



}
