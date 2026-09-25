#include<bits/stdc++.h>
using namespace std;



int main() {
    // std::array<T, N> is a thin weapper around a raw C-style array, giving it STL-compatible structure - iterators,
    // range-for, size9), algorithm compatibility, etc. while keeping the array stack aloocated and fixed size.
    // Both T and N are compile time constants same constraint as a bitset

    //! Internal Mechanics
    // This is the most simple container in the STL library
        // template <typename T, size_t N>
        // struct array {
        //     T _data[N];
        // };
    
    //! How is it different from the Raw C array:
    // raw C array problems:
    /*
    int arr[5] = {1,2,3,4,5};
    arr.size();           // won't compile -- no member functions
    sort(arr, arr+5);     // works but ugly, need to track size manually
    void f(int arr[]);  // array decays to pointer, size is LOST
    int arr2[5] = arr;    // won't compile -- can't copy assign
    
    // std::array solutions:
    array<int,5> a = {1,2,3,4,5};
    a.size();             // 5 -- works
    sort(a.begin(), a.end()); // works cleanly
    void f(array<int,5> a); // size is part of the type, no decay
    array<int,5> b = a;   // copy works
    */
    
    //* Essential Syntax: inside <array> library
    array<int, 5> a = {1, 2, 3, 4, 5};
    array<int, 5> b{};              //All values initialized with 0
    array<int, 5> c;                //All values uninitialized

    //Access
    a[2];                           // 3 - but no bound check
    a.at(2);                        // 3 - but checks bound and throws error if outside the bound
    a.front();                      // Gives first element
    a.back();                       // Gives last element
    a.data();                       // Raw pointer to underlying array to use with C API
    a.size();                       // Returns 5
    a.empty();                      // false (only true if N == 0)
    a.fill(0);                      // Set all elements to 0
    a.swap(b);                      // Swaps two array

    //array support iterator
    auto it = a.begin();

    return 0;
}