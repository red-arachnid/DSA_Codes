// Write a function void rotateLeft(vector<int>& v, int k) that rotates the vector left by k positions using 
// only iterator operations — no indexing with [], no creating a second vector.

#include<bits/stdc++.h>
using namespace std;

void rotateLeft(vector<int>& v, int k) {
    rotate(v.begin(), v.begin()+k, v.end());
}
void rotateRight(vector<int>& v, int k) {
    rotate(v.begin(), v.end()-k, v.end());
}

int main() {
    vector<int> v1 = {1,2,3,4,5};
    rotateLeft(v1, 2);
    for (int x : v1) {
        cout << x << " ";
    }
    cout << '\n';
    rotateRight(v1, 2);
    rotateRight(v1, 2);
    for (int x : v1) {
        cout << x << " ";
    }
    cout << '\n';
    return 0;
}