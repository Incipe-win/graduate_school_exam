#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int suffix_expression_evaluation(const string &str) {
    stack<int> st;
    for (const auto &ch : str) {
        int left, right, res;
        if (isdigit(ch)) {
            st.push(ch - '0');
        } else {
            right = st.top();
            st.pop();
            left = st.top();
            st.pop();
            if (ch == '+') {
                res = left + right;
                st.push(res);
            } else if (ch == '-') {
                res = left - right;
                st.push(res);
            } else if (ch == '*') {
                res = left * right;
                st.push(res);
            } else if (ch == '/') {
                res = left / right;
                st.push(res);
            }
        }
    }
    return st.top();
}

int main() {
    string str;
    while (cin >> str) {
        cout << suffix_expression_evaluation(str) << endl;
    }
    return 0;
}