#include<bits/stdc++.h>
using namespace std;


int main() {
    //! What is an iterator
    // An iterator is any object that satisfies a specific concept (A set of operations it must support)
    // It's modeleed on raw pointers (a raw int* is itself a valid random-access iterator).
    // The STL generaizes this, instead of requiring a pointer, algorithms require something that behaves like a pointer.
    //Concretely, every pointer must support at minimun:
    //*         *it operation
    //*         ++it operation
    //*         it != end comparision

    //! Five catergories of iterator (in hierarchy)
    // Input/Output <- Forward <- Bidirectional <- Random Access <- Contiguous
    // Each level is a strict superset of the level left to it.
    // A random access iterator can do everthing a bidirectional iterator can, plus more.

    //* Input iterator : Read only, single pass, forward only
    istream_iterator<int> it(cin), end;
    while (it != end) { cout << *it; it++; }  // Cannot go back (it--)

    //* Output Iterator : Write only, single pass, forward only
    ostream_iterator<int> out(cout, ", ");
    *out = 42; ++out;       // Writes to cout

    vector<int> v;
    fill_n(back_inserter(v), 5, 99);        //Pushes five 99 into v
    // back_inserter(v) returns an iterator (it) that works the same as push_back();
    // assigning *it = 5 is similar to v.push_back(5);


    //* Forward iterator : Read/Write, multi pass, forward only
    forward_list<int> fl = {1, 2, 3};
    auto itf = fl.begin();      //Simple iterator that only moves forward (used in forward linked list)
    auto copy = itf;

    //* Bidirection iterator : forward iterator + can go backward
    list<int> l = {1, 2, 3};
    auto itb = l.end();
    --itb; ++itb;       //Both works

    //* Random Access Iterator : bidirectional + jump anywhere in O(1)
    vector<int> v1 = {1, 2, 3, 4, 5};
    auto itr = v1.begin();
    itr += 3;        //Jump 3 forward
    itr[1];          //Same as *(it+1)
    
    //* Contiguous Iterator (C++17) : Random Access + elements are contiguous in memory
    // adds guarantee: &*(it+n) == &*it + n  (pointer arithmetic works)
    // containers: vector, array, string (but NOT deque -- chunked memory)
    // enables: memcpy optimizations, SIMD, passing .data() to C APIs

    //! Which container gives which iterator:
    /*
        vector - Random Access (Contiguous)
        array - Random Access (Contiguous)
        deque - Random Access
        list - Bidirectional
        forward_list - Forward
        set / map / multiset / multimap - Bidirectional
        unordered_set / unordered_map - Forward
        stack / queue / priority_queue - No Iterator
    */

    //! Why the types matter
    // std::sort requires random access iterators, anything above won't compile
    // std::distance and std::advance are O(1) for random access and O(n) for everthing else

    //* Iterator utility function
    auto newIt = v1.begin();
    advance(newIt, 3);                  //Move the newIt by 3 step
    auto newIt2 = next(newIt, 2);       // No changes in newIt, newIt2 is 2 steps ahead
    auto newIt3 = prev(v1.end(), 1);
    distance(v1.begin(), v1.end());       // Number of steps from begin() to end() = v.size()

    // Reverse Iterators : Present in every bidirection+ iterators
    auto rIt = v1.rbegin();      // Points to 5
    auto fIt = rIt.base();       // Points to v1.end();
    fIt--;                       // Now points to 5

    //! const_iterator
    // An iterator that is read only
    vector<int>::iterator vit = v1.begin();         //*vit = 10; works
    vector<int>::const_iterator cit = v1.cbegin();  //*cit = 10; won't compile

    return 0;
}