//
// Created by egorm on 21.11.2023.
//

#ifndef UNTITLED_TPOSTFIX_H
#define UNTITLED_TPOSTFIX_H

#include <vector>
#include <string>
#include <iostream>
#include "TStack.h"

using namespace std;

class TPostfix {
public:
    static string to_postfix(string s) {
        cout<<"Your example - "<<s<<endl;
        string res = "";
        TStack<char> stack;
        for (int i = 0; i < s.length(); ++i) {
            if (check_symb(s[i])) {
                switch (s[i]) {
                    case '*':
                    case '(':
                        stack.push(s[i]);
                        break;
                    case '+':
                        while (!stack.isEmpty() && stack.top() != '(') {
                            char c = stack.pop();
                            res += c;
                        }
//                        if(stack.top() == '(')
//                            stack.pop();
                        stack.push('+');
                        break;
                    case ')':
                        while (!stack.isEmpty() && stack.top() != '(') {
                            char c = stack.pop();
                            res += c;
                        }
                        if (stack.top() == '(')
                            stack.pop();
                        break;


                }
            } else {
                res += s[i];
            }
//            cout<<s[i]<<" "<<res<<" "<<stack.getSize()<<endl;
        }
        while (!stack.isEmpty()) {
            char c = stack.pop();
            res += c;
        }
        cout << "Postfix form  - " << res << endl;
        postfix_solve(res);
        return res;
    }

    static string postfix_solve(string s) {
        int i = 0;
        while (i < s.length()) {
//            cout<<i<<endl;
            if (check_symb(s[i])) {
                int a = s[i - 1] - '0';
                int b = s[i - 2] - '0';

                int res = get_res(a, b, s[i]);
//             cout<<a<<" "<<b<<" "<<res<<endl;
                s.replace(i - 2, 3, to_string(res));
                i--;
            } else {
                i++;
            }
//            cout << s << endl;
        }
        cout << "Result - " << s << endl;

        return s;
    }

    static int get_res(int a, int b, char c) {
        switch (c) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            default:
                return -1;
        }
    }

    static bool check_symb(char c) {
        if (c == '+' || c == '*' || c == '-' || c == '(' || c == ')')
            return true;
        return false;
    }
};


#endif //UNTITLED_TPOSTFIX_H
