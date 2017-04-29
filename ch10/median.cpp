#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <iostream>
using namespace std;

void median(istringstream& sin) {
    int x;
    // max heap holds lowest elements in array
    // MAX heap is with LESS opereation
    priority_queue<int, vector<int>, less<int>> L;
    priority_queue<int, vector<int>, greater<int>> H;

    while (sin >> x) {
        if (L.size() > 0 && L.top() < x) {
            H.emplace(x);
        } else {
            L.emplace(x);
        }
        if (H.size() + 1 < L.size()) {
            H.emplace(L.top());
            L.pop();
        } else if (L.size() + 1 < H.size()) {
            L.emplace(H.top());
            H.pop();
        }
    }
    if (L.size() == H.size() {
        cout << (L.top() + H.top()) * 0.5 << endl; 
    } else if (L.size() > H.size())
        return L.top();
    else
        return H.top();
}


int main() {    
    string s = "1 3 2 4 6 5";
    istringstream ss(s);
    median(ss);
}


