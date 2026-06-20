#include<bits/stdc++.h>
using namespace std;


int main() {
    //!NOTE: A Vector grows 2x its original size if a new element is insert when size() == capacity().
    // But since it doubles the initial space, the memory rarely need to reallocate the space until another N numbers of element are inserted.
    // So the time complexity for insertion `push_back` is O(1) [amortized]

    /*
    !Time Complexity: {
        v[i]/at(i) = O(1)
        push_back = O(1) [amortized]
        pop_back = O(1)
        insert(it, val) = O(n)
        erase(it) = O(n)
        size() = O(1)
    !}
    */

    //* Essential Syntax:
    vector<int> v1;                 // An empty vector of type int 
    vector<int> v2(5);              // A Vector with 5 elements, default value of 0
    vector<int> v3(5, 100);         // A Vector with 5 elements, all valued to 100
    vector<int> v4 = {1, 2, 3};     // A Vector initialized with values
    vector<int> v5(v4);             // Copied v4 in a new vector
    vector<vector<int>> matrix(3, vector<int>(3, 0)); // A 3x3 matrix, similar to arr[][]

    v1.push_back(10);               // Add new element at the end
    v1.emplace_back(20);            // Construct a new element instead of coping it and place it at the end 
    v1.pop_back();                  // Removes one element from the end
    // emplace_back is faster than push_back.
    // push_back is more used for an adding an already existing object at the end of vector.
    // emplace_back is for creating new objects directly within the vector.

    v1.size();                      // Returns the current elements in the vector
    v1.capacity();                  // Returns the actual capacity of vector
    v1.clear();                     // Removes all elements from the vector (No effect on capacity).
    v1.empty();                     // Checks if the vector has 0 elements without changing it.
    v1.front();                     // Reference of first element of vector (same as v1[0]).
    v1.back();                      // Reference of last element of vector (same as v1[v1.size() - 1]).
    // Accessing front() or back() in an empty vector can result in undefined behavior
    //! Use v1.empty() to check first before useing front() or back().

    v1.begin();                     // Returns a pointer pointing to the first index of vector
    v1.end();                       // Returns a pointer poiting to the last most index + 1 of the vector
    

    v1.insert(v1.begin() + 1, 101); // Insert 101 at the 2nd position
    v1.erase(v1.begin() + 1);       // Removes an element at the 2nd position
    v1.erase(v1.begin(), v1.begin() + 3); //Remove elements in the range [0, 3)


    v1.reserve(10);                 // Reserve the capacity of `10` for the vector
    v1.resize(20);                  // Resize the capacity of vector to 20 and initialize all elements to their default value (0 for int)


    //! Common iteration bug to remember: 
    //* Any operation that causes reallocation invalidates all existing iterators/pointers/references into the vector.
    // Right way to iterate for an erase or push_back operation
    for (auto it = v1.begin(); it != v1.end(); ) {
        if (*it == 4) it = v1.erase(it); // erase returns next valid iterator
        else ++it;
    }

    return 0;
}