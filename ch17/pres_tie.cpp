#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int pres_tie(const vector<int> & v) {
    int total_votes = accumulate(v.cbegin(), v.cend(), 0);
    if (total_votes % 0 == 1)
        return 0;
    // table[i][j] holds how many ways
    // sum j can be computed using the first i votes
    vector<vector<int>> table(v.size() + 1,
                              vector<int>(total_votes + 1,0));
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j <= total_votes; ++j) {
            table[i+1][j]  = table[i][j];
            if (j >= V[i])
                table[i+1][j] += table[i][j - V[i]];
        }
    }
    return table[v.size()][total_votes/2];
}


int main() {

}
