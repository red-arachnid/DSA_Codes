#include<bits/stdc++.h>
using namespace std;

int main() {
    // multimap<K, V> is exactly like map except it allows duplcate keys.
    // Multiple entries can share the same key, each with a different (or even the same) value.

    // !Internal Mechanics
    //      The difference between map and multimap is purely in the insertion policy
    //      map::insert checks if the key already exists and rejects duplicated
    //      multimap::insert always inserts unconditionally, allowing multiple nodes with identical keys
    //      These duplicate-key nodes are stored in insertion order relative to each other
    //      ALl other keys are still sorted by the key values

    //* Multimap does not have operator[] because with duplicate keys, m[key] would be ambiguous
    // Same goes for .at() method. The only way to access value is by iteration or range-query functions

    //* Essential Syntax : inside <map> library
    multimap<int, string> mm;
    mm.insert({1, "apple"});        // Only way to insert in multimap mm[1] = "apple" does not work
    mm.insert({2, "banana"});
    mm.insert({2, "Berry"});
    mm.insert({1, "avacado"});

    mm.size();                      // Gives 3
    mm.count(1);                    // Gives 2 (there are two entries with key 1)

    auto it = mm.find(1);           // points to first entry of key 1 (1, "apple")
    mm.erase(2);                    //Removes all the entries with key at 2. Also works with iterator (mm.erase(it))       

    // Use 'equal_range' to get all the entries of a key
    auto [lo, hi] = mm.equal_range(1);  // Gives a pair of iterator from first to last position
    for (auto it = lo; it != hi; it++) {
        cout << it->first << ": " << it->second << "\n";
    }

    //lower_bound and upper_bound works on multimap as well

    //! Multimap is not commonly used it programming as a map<int, vector<string>> can do the same work with index access
}