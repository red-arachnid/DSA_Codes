#include<bits/stdc++.h>
using namespace std;


int main() {
    // Deque stands for double ended queue.
    
    //* How Deque works internally: 
    // Deque is not one contiguous block like vector.
    // It is implimented as a sequence of fixed-size chunks/blocks with a small index structure that tracks where each block lives.
    // It is more like multiple vector of same capacity grouped together and their address stored in the deque.
    // This is why a deque can do O(1) push at front and back, as it does not have to shift all exiting element just add a new block at the start
    // Random access is still O(1) in deque but it is slightly slower compared to vector, since it involves a small computation to find the correct block


    /*
    !Time Complexity : {
        push_back = O(1) amortized
        push_front = O(1) amortized
        Random access = O(1) , but still slower than vector
        Insert/erase at index = O(n)
    !}
    */

    //* Essential Syntac : inside <deque> library
    deque<int> dq;
    dq.push_back(10);
    dq.push_front(20);
    dq.emplace_front(30);
    dq.emplace_back(40);
    dq.pop_back();
    dq.pop_front();

    dq.front(); dq.back();
    dq.size(); dq.empty();

    dq.begin(); dq.end();

    //Sort function supports deque:
    sort(dq.begin(), dq.end());


    return 0;
}