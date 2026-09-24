#include<bits/stdc++.h>
using namespace std;

int main() {
    // tuple<T1, T2, ..., Tn> is the generalization of pair to any number of elements. 
    // pair is fixed at exactly two members, but tuple can hold more than two all potentially of different types.
    // It is a compile time fixed size heterogeneous collection

    //! Internal Mechanics
    // tuple is implemented via recursive template inheritance under the hood - each layer of the template holds 
    // one element and inherits from the tuple of the remaining elements. This means the elements are laid out in 
    // memory similar to a struct, with no heap allocation, no pointers.
    // It is pure value type just like pair

    // Because indexing is done at compile time (get<0>, get<1>, etc.), you cannot index a tuple with a runtime variable 
    // [get<i>(t)] where i is a runtime int won't compile. This is the fundamental limitation of tuple vs. 
    // a runtime container like vector.

    //* Essential Sytax : inside <tuple> library
    tuple<int, string, double> t1(1, "hello", 3.14);
    auto t2 = make_tuple(2, "world", 2.71);
    auto t3 = tuple(3, "cpp", 1.41);                // Three ways to make a tuple

    // Access a tuple by index
    get<0>(t1);     // 1
    get<1>(t1);     // "hello"
    get<2>(t1);     // 3.14

    // Access by type
    get<string>(t1);// "hello"

    // Can be modified through get
    get<0>(t1) = 11;
    
    auto [x, y, z] = t1;        //unpack a tuple
    int a; string b; double c;
    tie(a, b, c) = t1;          //unpack a tuple method 2
    tie(a, ignore, c) = t1;     //skip the string

    tuple_size<decltype(t1)>::value;        // 3 (size at compile time)
    tuple_element<0, decltype(t1)>::type;   // type of element at compile time

    // tuples are compared lexicographically which means
    auto t11 = make_tuple(1, 2, 3);
    auto t12 = make_tuple(1, 2, 4);
    t11 < t12;          // Is true
    auto newT = tuple_cat(t11, t12);        // Make a new tuple with int, int, int, int, int, int

    //* When to use tuple + alternative
    //  Exactly 2 values - pair
    //  3+ values only used once / ad-hoc - tuple
    //  3+ values used frequently - struct
    //  Returining multiple values from a function - tuple which can be unpacked
    //  Heterogeneous collection with runtime indexing - Not possible with tuple

    //! In competitive programming, tuple<int,int,int> is extremely common for storing 
    //! graph edges (weight, u, v) in a priority queue or sorting edges by weight
    vector<tuple<int, int, int>> edges; // weight, u, v
    edges.emplace_back(5,0,1);

    //*A neat trick - can use tie to implement operator< for a struct without writing comparison logic manually:
    struct Task {
        int priority, deadline;
        string name;

        bool operator<(const Task& o) const {
            return tie(priority, deadline, name) < tie(o.priority, o.deadline, o.name);
            // Simple one line comparision between priority, deadline and name
            // instead of using nested if statements
        }
    };
}