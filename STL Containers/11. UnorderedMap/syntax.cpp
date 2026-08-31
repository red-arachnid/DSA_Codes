#include<bits/stdc++.h>
using namespace std;

int main() {
    // Works the same way as an unordered set but for a map
    // Hashesh the key value pair in buckets using the key
    // Unordered Map also supports custom hash function same as an unordered Set
    // Unordered Map provieds O(1) access/insert time but do not support upper_bound and lower_bound
    // * Found in <unordered_map> library

    //!Example of Simple hash functor for unordered map:
    struct PairHash {
        size_t operator()(const pair<int, int>& p) const {
            size_t h1 = hash<int>()(p.first);
            size_t h2 = hash<int>()(p.second);
            return h1 ^ (h2 << 32);
        }
    };
    unordered_map<pair<int, int>, int, PairHash> m;


    return 0;
}