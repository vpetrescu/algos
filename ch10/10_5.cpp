#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> split(const vector<int>& A) {
    bool is_increasing = true;
    int start_idx = 0;
    vector<vector<int>> out;
    for (int i = 1; i < A.size(); ++i) {
        if (is_increasing && A[i-1] > A[i]) {
            // copy from start_idx to i
            out.emplace_back(A.begin() + start_idx, A.begin() +i);
            start_idx = i;
            is_increasing = !is_increasing;
        } else if (!is_increasing && A[i-1] <= A[i]) {
            vector<int> tmp (A.begin() + start_idx, A.begin() +i);
            reverse(tmp.begin(), tmp.end());
            out.emplace_back(tmp);
            start_idx = i;
            is_increasing = !is_increasing;
        }
    }
    // last element
    out.emplace_back(A.begin()+start_idx, A.end());
    return out;
}

int main() {
    vector<int> a = {10,20,30,40,35,25,15,17,35,32};
    vector<vector<int>> out = split(a);
    for (int i = 0; i < out.size(); ++i) {
        for (int j = 0; j < out[i].size(); ++j)
            cout << out[i][j] << " ";
        cout << endl;
    }
}

