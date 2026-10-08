#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {

    int n, m;
    cin >> n >> m;
    
    vector<string> laby(n);
    queue<pair<int, int>> q;
    int aRow, aCol, bRow, bCol;
    // Keeping track of the coords for A and coords for B
    for (int i = 0; i < n; i++) {
        cin >> laby[i];                     // Shortcut to intake whole row into current column
        for (int j = 0; j < m; j++) {
            if (laby[i][j] == 'A') {
                aRow = i;
                aCol = j;
                q.push({i, j});
            }
            else if (laby[i][j] == 'B') {
                bRow = i;
                bCol = j;
            }
        }
    }

    // right, up, down, left
    vector<pair<int, int>> moves {{0,1}, {-1,0}, {1,0}, {0,-1}};
    vector<vector<int>> arrive(n, vector<int>(m, -1));

    // This BFS was done to mark the path to the destination
    while (!q.empty()) {
        int row = q.front().first, col = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nextR = row + moves[i].first, nextC = col + moves[i].second;
            if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && 
            laby[nextR][nextC] != '#' && arrive[nextR][nextC] == -1) {
                arrive[nextR][nextC] = i;
                q.push({nextR, nextC});
            }
        }
    }

    // We can check the index for B to make sure it was visited;
    if (arrive[bRow][bCol] == -1) {
        cout << "NO";
    }
    else {
        string res = "", dir = "RUDL";
        int row = bRow, col = bCol;
        while (row != aRow || col != aCol) {
            int idx = arrive[row][col];
            res += dir[idx];
            row -= moves[idx].first;
            col -= moves[idx].second;
        }
        reverse(res.begin(), res.end());
        cout << "YES" << endl;
        cout << res.length() << endl;
        cout << res;
    }
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t; // Uncomment if the problem has multiple test cases
    while (t--) {
        solve();
    }
    return 0;
}