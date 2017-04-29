#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <iostream>
using namespace std;

void kth_sorted(istringstream& sin, const int& k) {
    int x;
    // min priority queue
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < k && sin >> x; ++i) {
        q.emplace(x);
    }
    while (sin >> x) {
        // k + 1 elements
        q.emplace(x);
        cout << q.top() << endl;
        q.pop();
    }
    while (!q.empty()) {
        cout << q.top() << endl;
        q.pop(); 
    }
}


int main() {    
    string s = "1 3 2 4 6 5";
    istringstream ss(s);
    kth_sorted(ss, 3);
}
