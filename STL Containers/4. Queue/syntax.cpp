#include<bits/stdc++.h>
using namespace std;

int main() {
    // Queue is a container adapter - not a standalone data structure.
    // It does not implement its own storage but wraps another container [default (deque)]
    // and restricts the interface to FIFO operation only.
    // !Defined in the <queue> library

    queue<int> q1; // An empty queue with the base container as deque.
    queue<int, list<int>> q2; // An empty queue with the base container as list.
    //! The base container (or underlying container) can be swapped as long as it supports `front()`, `back()`, `push_back()`, `pop_front()`.

    // *Q. Why does queue uses deque as a default underlying container instead of other containers like vector.
    // ANS: A queue needs efficient push at one end and pop at the other end operation. Vector is O(1) at the back but O(n) 
    //      at the front. Deque on the other hand is usually implemented as a sequence of fixed-size blocks with an index structure.
    //      giving O(1) push/posh at both ends, while still supporting random access.

    //* Essential Syntax of queue : 
    queue<int> q;
    q.push(10);                     // Adds 10 to the back
    q.push(20);                     // 10 - 20
    q.push(30);                     // 10 - 20 - 30

    q.front();                      // Give the first element of queue. (The first one to come out on pop)
    q.back();                       // Gives the last element of the queue. (The most recently added)
    q.pop();                        // Removes from front //!No Return Value
    q.size();                       // Size of the queue
    q.empty();                      // Checks if the queue has any element or not

    //! All queue operation are O(1) in time complexity
    // Iteration is not allowed in queue as it violates the whole purpose of using a queue.


    //* Queue is commonly used in BFS (Breadth-First Search) on graphs and trees.

    return 0;
}