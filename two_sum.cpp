#include <string>
#include <map>
#include<math.h>
#include <vector>
#include <iostream>
using namespace std;

int getSum(int a, int b) {
    int mask = 1;
    int carry = 0;
    int result = 0;
    while (mask) {
        int a_mask = a& mask;
        int b_mask = b& mask;
        result = result | (a_mask ^ b_mask ^ carry);
        carry = (a_mask & carry) | (a_mask & b_mask) | (b_mask & carry);
        carry = carry << 1;
        mask = mask << 1;
    }
    return result;
}

int main() {
    cout << 9 << " " << getSum(5,4) << endl;
    cout << -1 << " " << getSum(-10,2) << endl;
    cout << 1 << " " << getSum(2,-12) << endl;
    cout << 1 << " " << getSum(-5,-40) << endl;
}


