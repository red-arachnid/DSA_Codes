#include<bits/stdc++.h>
using namespace std;

int main() {
    // map<K, V> stores key-value pairs with unique keys, sorted by key. It's the associative container 
    // given a key, get its associated value in O(log n). Same Red-Black Tree backing as set, 
    // except each node stores a pair<const K, V> instead of just a value.

    // Iterating a map gives result in sorted order by key form
    //! The value of a key can be modified but the key itself is a constant as it is stored in the form of pair<const K, V>
    
    //* Essential Syntax : inside <map> library
    map<string, int> m;
    m["apple"] = 5;             // Creates a string key "apple" and gives it a value of 5.
    m.insert({"banana", 3});    // Creates a string key "banana" with the value of 3.
    m.emplace("cherry", 7);     // Consturcts in place, slightly efficient than insert

    //To Access
    m["apple"];                 // Returns 5 or makes a new key value pair if the key "apple" does not exist
    m.at("apple");              // Returns 5 or throws out of bound error if not present (More safer and bug free)
    m.count("apple");           // Returns 1 if present else 0
    m.find("apple");            // Returns iterator or m.end() if not present
    m.size();
    m.empty();

    //Erase
    m.erase("banana");          // Erase by key O(log n)
    m.erase(m.find("cherry"));  // Erase by iterator O(1) [If the iterator is already known]

    //Iterate a map
    for (auto& [key, value] : m) {  //Or use auto& p : m where p is a pair [p.first -> key, p.second -> value]
        cout << key << ": " << value << "\n";
    }

    // Map supports lower_bound and upper_bound same as set.

    return 0;
}