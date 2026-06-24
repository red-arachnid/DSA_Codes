#include<bits/stdc++.h>
using namespace std;

int main() {
    // The sort() function does not work on list as list does not work on random-access iterator
    // That is why list has its own sort method that works on merge sort algorithm [O(nlogn)]

    /*
    !Time Complexity : {
        push_back = O(1)
        push_front = O(1)
        insert = O(n)
        erase = O(n) for iterated value and O(1) for known pointer
    !}    
    */

    // Even though both list and vector are "O(n) to traverse," 
    // a vector traversal is dramatically faster in real wall-clock time because of CPU cache prefetching. 
    // Linked lists scatter nodes all over the heap.

    //* Essential Syntax : from <list> library
    list<int> l1;                       // Creates an empty list with no start and end to null
    list<int> l2 = {1, 2, 3};           // Creates a list with 3 nodes. 1 is front and 3 is end.
    list<int> l3(5, 100);               // Creates a list with 5 nodes each containing the value 100.

    l1.push_back(10);                   // Adds 10 to the end of list
    l1.push_front(5);                   // Adds 5 to the front of list
    l1.pop_back();                      // Removes the last element / node of list
    l1.pop_front();                     // Removes the first element / node of list
    l1.front();                         // Reference of the first element of the list
    l1.back();                          // Reference of the last element of the list
    //! Do not call front and back on a list without checking the empty() method first.

    // For list iteration
    auto it = l1.begin();               // Returns a poitner to the first element of the list
    auto itEnd = l1.end();              // Returns a pointer to the last element + 1 of the list.
    advance(it, 2);                     // Moves `it` forward by 2 steps, O(n) [no jumping].

    l1.insert(it, 99);                  // Adds before the given iterator. Eg: 1-2-3 (it=1) => 1-99-2-3 O(1)
    it = l1.erase(it);                  // Removes the node at current iterator and returns the next iterator O(1).
    l1.remove(5);                       // Remove all element that are equal to 5
    l1.remove_if([](int x){ return x % 2 == 0; }); // Similar to the filter method of array in js.

    l1.sort();                          // Sorts the list using merge sort O(nlogn)
    l1.reverse();                       // Reverse the entire list O(n)
    l1.unique();                        // Removes CONSECUTIVE duplicates [Pair with sort() for a totally unique list]
    l1.merge(l2);                       // mergest two SORTED lists into one sorted list [l2 becoms empty]
    l1.splice(it, l2);                  // Moves all of l2 into l1 before position it -- O(1)! no copying, just relinks nodes


    //! Erasing or Inserting a node in a list only invalidates the iterator to that specific erased node,
    //! every other iterator into list remvains valid. [Contrast to Vectors where every iterator after modification point is invalid]

    return 0;
}