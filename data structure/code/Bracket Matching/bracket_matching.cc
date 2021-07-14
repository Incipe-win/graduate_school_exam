#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool bracket_check(const string &str) {
    stack<char> st;
    for (const auto &ch : str) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } else {
            if (st.empty()) {
                return false;
            }
            char top_elem = st.top();
            st.pop();
            if (ch == ')' && top_elem != '(') {
                return false;
            }
            if (ch == ']' && top_elem != '[') {
                return false;
            }
            if (ch == '}' && top_elem != '{') {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string str = "((())){}[]{}";
    if (bracket_check(str)) {
        cout << "The bracket is vaild!" << endl;
    } else {
        cout << "The bracket is invaild!" << endl;
    }
    return 0;
}