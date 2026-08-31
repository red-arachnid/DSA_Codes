// Given a list of strings, group them into anagram families : strings that are anagrams of each other 
// go in the same group. Print each group on one line, groups in any order, strings within a group in any order.

//! Anagram - A word or phrase formed by reordering the letters of another word or phrase, such as satin to stain.

#include<bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string>> findAnagramGroups(vector<string> words) {
    unordered_map<string, vector<string>> result;

    for (string& s : words) {
        string key = s;
        sort(key.begin(), key.end());
        result[key].push_back(s);
    }

    return result;
}

int main() {
    for (auto& [key, value] : findAnagramGroups({"eat","tea","tan","ate","nat","bat"})) {
        cout << "{";
        for (string s : value) {
            cout << s << ",";
        }
        cout << "\b}, ";
    }
    cout << "\b\b\n";
    return 0;
}