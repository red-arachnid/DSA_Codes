#include<bits/stdc++.h>
using namespace std;

int main() {
    // Priority Queue is a container adapter that gives O(1) access to the largest element 

    //! It is, in essence, a heap — specifically a max-heap by default.

    //* HEAP :-
    // A heap is a complete binary tree stored implicitly in an array (the underlying vector), 
    // satisfying the heap property: every parent is greater than or equal to its children (max-heap).
    // "Stored implicitly" means there are no node/pointer allocations — the tree structure is encoded
    // purely by index arithmetic

    // !For element at index i:
    //   parent:       (i - 1) / 2
    //   left child:   2*i + 1
    //   right child:  2*i + 2

    // A priority queue has 3 major operation:
    // 1. Push O(logn) : Append a new element at the end then shift up until the heap property is restored.
    // 2. Pop O(logn) : Removes the max element (root) after swapping it with the last element and then shift the tree back in order
    // 3. Top O(1) : Returns the max element (root) of the tree

    //* Essential Syntax : inside <queue> library 
    priority_queue<int> pq;
    pq.push(20);
    pq.push(30);
    pq.push(40);
    /*
            40
          /   \
         20    30
    */
   pq.top();        //Returns 40
   pq.pop();        //Removes 40
   pq.size();       //3 for this priority queue
   pq.empty();      //Checks if the priority queue is empty or not


    //! Minimum Heap
    // By default it's a max-heap. To flip it to a min-heap (smallest element at top), 
    // Passing greater<T> as the comparator. The syntax is slightly verbose as we have to specify the  underlying container.

    priority_queue<int, vector<int>, greater<int>> minpq;
    minpq.push(20);
    minpq.push(10);
    minpq.push(40);         //10 is the root node here
    //! Minimum heap is just in a lot of algorithms like Dijkstra's algorithm, merge k sorted lists, etc.

    


    return 0;
}