#include<bits/stdc++.h>
using namespace std;

int main() {
    // Like queue, stack is also a container adapter but it follows the priciple of LIFO
    // By default the underlying container of stack is also deque but a vector is common preferred.
    //! The design priciple are same for both queue and stack

    //* Essential Syntax of stack : in <stack> library

    stack<int> s;
    s.push(10);             // Adds element at the end
    s.push(20);             // 10 - 20
    s.push(30);             // 10 - 20 - 30

    s.top();                // Returns the mostl recently pushed element
    s.pop();                // Removes the most recently pushed element
    s.size();
    s.empty();

    //! All stack operation are O(1) in time complexity
    // Iteration is not allowed in stack as it violates the whole purpose of using a stack.


    //* Stack is commonly used in DFS (Depth-First Search) on graphs and trees.

    return 0;
}