/**************************************************
 *   This program has bug,                        *
 *   for example,                                 *
 *   it can't solve decimals,                     *
 *   Operands are preceded by pluses and minuses. *
 **************************************************/

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

string infix2suffix(const string &str) {
    stack<char> st;
    string res = "";
    for (const auto &ch : str) {
        char top_elem;
        if (isdigit(ch)) {
            res += ch;
        } else if (ch == '+' || ch == '-') {
            while (!st.empty() && (top_elem = st.top()) != '(') {
                res += top_elem;
                st.pop();
            }
            st.push(ch);
        } else if (ch == '*' || ch == '/' || ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (!st.empty() && (top_elem = st.top()) != '(') {
                res += top_elem;
                st.pop();
            }
            st.pop();
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

string infix2suffix_enhance(const string &str) {
    stack<char> st;
    string res = "";
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    for (const auto &ch : str) {
        if (isdigit(ch)) {
            res += ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && pr[st.top()] >= pr[ch]) {
                res += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

int main() {
    // string str = "1+2-3*4";
    // 12+34*-
    // string str = "1+2*(3-4)-5/6";
    // 1234-*+56/-
    // string str = "2+3*(7-4)+8/4";
    // 2 3 7 4 - * + 8 4 / +
    string str;
    while (cin >> str) {
        // string res = infix2suffix(str);
        string res = infix2suffix_enhance(str);
        cout << res << endl;
    }
    return 0;
}