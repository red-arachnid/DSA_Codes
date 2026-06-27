// Given a string containing only (, ), {, }, [, ], determine if it's balanced — every 
// opening bracket has a matching closing bracket of the same type, in the correct order.

#include<bits/stdc++.h>
using namespace std;

bool isExpressionBalanced(string expr) {
    stack<char> s;

    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        else {
            if (s.empty()) return false;

            char top = s.top();
            s.pop();
            
            if (top == '(' && c == ')') continue;
            if (top == '[' && c == ']') continue;
            if (top == '{' && c == '}') continue;

            return false;
        }
    }

    return true;
}

int main() {
    string expr1 = "()[]{}";
    string expr2 = "(]";
    string expr3 = "([{}])";
    string expr4 = ")";
    string expr5 = "";

    cout << expr1 << " is " << (isExpressionBalanced(expr1) ? "valid." : "not valid.") << "\n";
    cout << expr2 << " is " << (isExpressionBalanced(expr2) ? "valid." : "not valid.") << "\n";
    cout << expr3 << " is " << (isExpressionBalanced(expr3) ? "valid." : "not valid.") << "\n";
    cout << expr4 << " is " << (isExpressionBalanced(expr4) ? "valid." : "not valid.") << "\n";
    cout << expr5 << " is " << (isExpressionBalanced(expr5) ? "valid." : "not valid.") << "\n";
    return 0;
}