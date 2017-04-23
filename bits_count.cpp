#include <vector>
#include <iostream>

using namespace std;
vector<int> count_bits(int n) {
    vector<int> out(n, 0);
    out[0] = 0;
    out[1] = 1;
    int i = 2;
    int idx = 0;
    int pow_2 = 2;
    while (i <= n) {
        if (i == pow_2)
                idx = 0;
        while (i <=n && i < pow_2 * 2) {
            out[i] = 1 + out[idx];
            i++; idx++;
        }
        pow_2 *= 2;
    }
    return out;
}

int main() {
    vector<int> out = count_bits(25);
    for (auto & a: out)
       cout << a << " ";
    cout << endl;
}
