// Given a string, count the frequency of each character and print them in alphabetical order with their counts. 
// Then find and print the most frequent character

#include<bits/stdc++.h>
using namespace std;

void frequencyCounter(string s) {
    if (s.empty()) {
        cout << "\n\n";
        return;
    }

    map<char, int> freq;
    char mostFrequent = s[0];

    for (char& c : s) {
        freq[c]++;
    }

    for (auto& [key, value] : freq) {
        cout << key << ":" << value << ", ";

        if (value > freq.at(mostFrequent)) mostFrequent = key;
    }
    cout << "\b\b\n";
    cout << "Most Frequent - " << mostFrequent << "\n\n";

}

int main() {
    frequencyCounter("abracadabra");
    frequencyCounter("aabb");
    frequencyCounter("z");
    frequencyCounter("zzaabb");
    frequencyCounter("");
    
    return 0;
}