// Implement a simple palindrome checker using a deque

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    deque<char> dq;

    for (char c : s) {
        dq.push_back(c);
    }

    while (!dq.empty()) {
        if (dq.size() == 1) {
            return true;
        }
        else if (dq.front() == dq.back()) {
            dq.pop_back();
            dq.pop_front();
        }
        else return false;
    }
    return true;
}

int main() {
    string a = "racecar";
    string b = "hello";
    string c = "abca";
    string d = "";
    string e = "a";

    cout << a << ((isPalindrome(a)) ? " is a palindrome.\n" : " is not a palindrome.\n");
    cout << b << ((isPalindrome(b)) ? " is a palindrome.\n" : " is not a palindrome.\n");
    cout << c << ((isPalindrome(c)) ? " is a palindrome.\n" : " is not a palindrome.\n");
    cout << d << ((isPalindrome(d)) ? " is a palindrome.\n" : " is not a palindrome.\n");
    cout << e << ((isPalindrome(e)) ? " is a palindrome.\n" : " is not a palindrome.\n");

    return 0;
}