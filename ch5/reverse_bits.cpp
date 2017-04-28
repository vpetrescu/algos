#include <iostream>

using namespace std;

uint32_t reverseBits(uint32_t n) {
    for (int i = 0; i < 16; ++i) {
        int j = 32 - i - 1;
        // swap elements if they differ
        if ((n >> i & 1) != (n >> j & 1)) {
              n = n ^ (1 << i | 1 << j);
        }
    } 
    return n;
}

int main() {
 cout << reverseBits(43261596) << endl;
}
