#include<bits/stdc++.h>
using namespace std;

int main() {
    // Multiset is to set what multimap is to a map.
    // Each inserted element gets iws own node in the tree, even if an identical value already exists.

    //! Multiset erase behavior [Differs from set]
    // erase(value) removes all matching elements, erase(iterator) removes that exact one element.

    //* Essential Syntax : inside <set> library
    multiset<int> ms;
    ms.insert(3);
    ms.insert(2);
    ms.insert(1);
    ms.insert(3);           // Does not ignore

    ms.size();              // Returns 4
    ms.count(3);            // Returns 2

    //Iteration:-
    for (int x : ms) cout << x; //1 2 3 3
    auto [lo, hi] = ms.equal_range(3);

    //! Usecase of multiset with frequency count:
    // A map of map<int, int> can keep the count of multiple occurence with (value, count) key pair [as used to find frequency]
    // Use a multiset when you need sorted iteration with duplcates naturally present,
    // or when using lower_bound/upper_bound frequently
    // Otherwise map works just fine

    //! Order Statistic pattern: 
    // multiset combined with lower_bound/upper_bound is frequently used to maintain a dynamic sorted sequence
    // where you insert and delete elements and query order statistics (min, max, kth smallest, count of element less than k)

    *ms.begin();    //min element;
    *ms.rbegin();   //max element;
    distance(ms.begin(), ms.lower_bound(4)); //Count of element strictly less than 4 [O(n)]
    
    //kth smallest element
    int k = 3;
    auto it = ms.begin();
    advance(it, k-1);       //O(k)
    *it;

    return 0;
}