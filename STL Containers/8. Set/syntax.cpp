#include<bits/stdc++.h>
using namespace std;

int main() {
    // Set is an ordered collection of unique elements. 
    // Its key properties are no duplicates, always sorted, and O(log n) insertion/deletion/search
    // It is implimeted as a self balancing binary tree (specially the Red-Black Tree)

    // Internally each node in a set holds:
    //    the element, a color bit, and pointers to parent/left child/right child.
    // This means every element in a set costs significantly more memory than the same element in a vector

    /*
    *Time complexity of basic operations {
        insert = O(log n)
        erase = O(log n)
        find = O(log n)
        count = O(log n)
        lower_bound = O(log n)
        upper_bound = O(log n)
        Full iteration = O(n)
        size = O(1)
    *}
    */

    // *Essential Syntax : inside <set> library
    set<int> s;
    set<int> s1 = {5, 3, 1, 6, 7}; //Auto sorts
    s.insert(5);
    s.insert(3);
    s.insert(7);
    s.insert(3); //Ignored 

    s.size();       //3
    s.count(3);     //Checks if three exists (returns 1)
    s.count(99);    //Checks if 99 exists (returns 0)
    
    s.erase(3);
    s.erase(s.begin()); // erase by iterator, O(1) amortized (since iterator already found)

    auto it = s.find(5); //Finds and returns iterator to element, s.end() if not found
    if (it != s.end()) cout << *it; //Prints 5

    // LOWER BOUND AND UPPER BOUND
    auto lb = s1.lower_bound(4); // iterator to first element >= 4 → points to 5
    auto ub = s1.upper_bound(5); // iterator to first element > 5 -> points to 6

    // This is the useful feature of set over unordered_set — because the tree is sorted, 
    // you can ask "what's the nearest element to x?" in O(log n). unordered_set can't do this.

    

    return 0;
}