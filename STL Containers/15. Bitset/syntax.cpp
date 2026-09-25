#include<bits/stdc++.h>
using namespace std;

int main() {
    // bitset<N> is a fixed size sequence of bits, where N is a compile time constant.
    // It's not a general-purpose container like vector but a specialized tool for bit manipulation at scale

    // The key value poroposition: operate on N bits simultaneously with single CPU instructions (via SIMD/ word level operations)
    // making bulk bit operation dramatically faster than looping over individual bits.

    //! Internal Mechanism:
    // Internally, bitset<N> stores its bits packed into an array of unsigned long (or unsigned long long) words
    // typically 64 bits per word(word is the memory block). So bitset<256> uses exactly 4*64 bit words 
    // which is equal to 42 bytes of storage, regardless of what is being stored.

    // Why this matters for performance: when you do b1 & b2 on two bitset<1024>, the CPU executes 
    // 16 × 64-bit AND instructions (one per word), not 1024 individual bit operations. This gives a 64x speedup 
    // over naive bit-by-bit processing. In competitive programming this constant factor 
    // often makes the difference between TLE and AC.

    //! N must be a compile time constant. Therefore
    bitset<8> ba;        //works
    const int N = 256;
    bitset<N> bb;       //works as well as const are compile time
    int n = 10;
    // bitset<n> bbb;      //does not work 
    // For dynamic-size bitset, use vector<bool> (which packs bits similarly) ,
    // but you lose the bulk operation speed and clean syntax.

    //* Essential Syntax : inside <bitset> library
    bitset<8> b1;               //All zeros: 00000000
    bitset<8> b2(42);           //From Interger: 00101010
    bitset<8> b3("11001010");   //From String: 11001010
    
    //Individual bits access:
    b1[0] = 1;                  //Right to left access: 00000001
    b1.set(3);                  //Set the 3rd bit from right to 1: 00001001
    b1.reset(0);                //Set the 0th bit from right to 0: 00001000
    b1.flip(3);                 //Toggle bits 3 0->1 or 1->0
    b1.flip();                  //Toggle all bits (a NOT operation)

    bool val = b1[2]; // read bit 2
    b1.test(2);       // same as b1[2] but throws out_of_range if invalid

    // bulk queries
    b1.count();       // number of 1-bits (popcount) -- O(N/64) word ops
    b1.size();        // N -- always 8 here
    b1.any();         // true if at least one bit is 1
    b1.none();        // true if all bits are 0
    b1.all();         // true if all bits are 1

    // bulk bitwise operations (these are the fast ones)
    bitset<8> a("10110100");
    bitset<8> b("11001010");

    a & b;   // AND:  10000000
    a | b;   // OR:   11111110
    a ^ b;   // XOR:  01111110
    ~a;      // NOT:  01001011

    a <<= 2; // left shift and assign:  11010000  (shift toward higher indices) 
    a >>= 1; // right shift and assign: 01101010  (shift toward lower indices)

    // conversion
    b2.to_ulong();   // convert to unsigned long (throws if N > 64 and high bits set)
    b2.to_ullong();  // convert to unsigned long long
    b2.to_string();  // "00101010"

    //! vector<bool> : a similar class
    // vector<bool> is a specialization (not a regular vector) that also packs bits, but it's 
    // notorious for breaking container semantics — operator[] doesn't return a bool&, 
    // it returns a proxy object, which means things like auto x = v[3] don't behave like you'd expect. 
    // Generally: use bitset when size is fixed and known at compile time, use vector<bool> only when
    // you need dynamic sizing and are aware of its quirks.
    

    return 0;
}