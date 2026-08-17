#include<bits/stdc++.h>
using namespace std;

int main() {
    // unordered_set<T> stores unique elements with no defined ordering, in exchange for O(1) 
    // average insert/erase/lookup instead of set's O(log n).

    // Internally an unordered_set maintains an array of buckets. When you insert an element,
    // it's hashed to determine which bucket it lands in, then stored there

    // The load factor is the ratio size / bucket_count. As you insert more elements and load factor grows, 
    // chains get longer and performance degrades. When load factor exceeds a threshold (default 1.0 in libstdc++), 
    // the table rehashes — allocates roughly double the buckets and reinserts everything. Rehash is O(n), 
    // but amortized over many inserts, average insert stays O(1).
    unordered_set<int> us = {1, 2, 3, 4, 5};
    us.load_factor();               // Average number of elements per bucket (size() / bucket_count())
    us.bucket_count();              // Total number of buckets in the hash table
    us.reserve(100);                // Pre allocate a number of bucket to prevent later reallocation

    /*
    Unordered Set works on hash table. A unique hash code is generated for every new element that is inserted and stored in
    an array of linked list (bucket). The index of the linked list the element will go is decided by the (hash code % number of buckets).
    If two element gets the same bucket then they are stored like => [Element 1] -> [Element 2] in the bucket
    The access time is generally considered O(1) as the bucket usually have very few elements in it.
    If the buckets receives a lot of element the access time might be O(n) of that linked list.
    To prevent this C++ unordered list implements a reallocation when the load_factor() gets over 1 (meaning there are more elements than buckets)
    and makes a new array of these bucket of size twice the size of previous bucket (same as vector).
    !That is why access of element in an unordered_set() is O(1) amortized.
    */

    //! WHAT IF ALL THE ELEMENTS HASH TO SAME BUCKET (EVEN THOUGH THE NUMBER OF ELEMENT ARE LESS THAN THE NUMBER OF BUCKETS)?
    /*
    If all elements hash to the same bucket, every operation degrades to O(n).
    The C++ unorder_set works on an identity hash [hash(x) = x)] but a custom hash can be made and passed to unorded_set
    to fix this problem.
    */
    //* Making a custom hash:
    struct SafeHash { // Creating a functor
        size_t operator()(uint32_t x) const {    //!Popularly known as the integer avalanche funciton 
            x = ((x >> 16) ^ x) * 0x45d9f3b;
            x = ((x >> 16) ^ x) * 0x45d9f3b;
            x = (x >> 16) ^ x;
            return x;
        }    
    };
    unordered_set<int, SafeHash> custom_us;

    //* Or a more popular hash that is used in competitive programming
    struct SafeHash {
        static uint64_t splitmix64(uint64_t x) {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }
        size_t operator()(uint64_t x) const {
            static const uint64_t FIXED_RANDOM =
                chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
        }
    };

    //* Essential Syntax : Exists in <unordered_set> library
    unordered_set<int> s;
    s.insert(5);
    s.insert(3);
    s.insert(5);    //Ignored as 5 is already inserted
    s.count(3);     // returns 1 if 3 is present else returns 0
    s.find(3);      // iterator to 3's position or s.end() is 3 is not present
    s.erase(3);

    for(int x : s) cout << x; //Random iteration as they are not ordered.


    //* unordered_set works for int, string, pointers and other primitive data types.
    // but for custom types like pair<int, int>, it always need a custom hash function.
    // For pair something like the Functor below can be used for hashing
    struct PairHash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<long long>()(((long long)p.first << 32) | (unsigned int)p.second);
        }
    };
    unordered_set<pair<int, int>, PairHash> pairSet;

    return 0;
}