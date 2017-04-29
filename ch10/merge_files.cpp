#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Compare {
    public:
            const bool operator()(const pair<int, int> & lhs,
                                  const pair<int, int> &rhs) {
                return lhs.first > rhs.first;
            }
};

vector<int> merge_arrays(const vector<vector<int>> & S) {
    // holds value of heap and index of sequence
    priority_queue<pair<int,int>, vector<pair<int, int>>, Compare> min_heap;
    // holds for every sequence, the index that was used.
    vector<int> S_idx(S.size(), 0);
    for (int i = 0; i < S.size(); ++i) {
        // add first elements to the heap
        if (S[i].size() > 0) {
            min_heap.emplace(make_pair(S[i][0], i));
            // element next to add in the array
            S_idx[i] = 1;
        }
    }
    vector<int> result;
    while (min_heap.size() != 0) {
        pair<int,int> tmp = min_heap.top();
        result.emplace_back(tmp.first);
        // Check index of sequence
        if (S_idx[tmp.second] < S[tmp.second].size()) {
            min_heap.emplace(make_pair(S[tmp.second][S_idx[tmp.second]],
                                            tmp.second));
            S_idx[tmp.second] += 1;
        }
        min_heap.pop();
    }
    return result;
}

int main() {
    vector<int> a = {1,12,32,41};
    vector<int> b = {10,20,30,40};
    vector<vector<int>> c(2);
    c[0] = a; c[1] = b;
    vector<int> out = merge_arrays(c);
    for (auto & a: out) {
        cout << a << " ";
    }
    cout << endl;
}

