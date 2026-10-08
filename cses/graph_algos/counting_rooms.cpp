#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n, m, res;
vector<vector<bool>> floor {};

bool isValid(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) { 
        return false;
    }
    if (floor[x][y]) {
        return false;
    }
    return true;
}

vector<pair<int, int>> moves {{1,0}, {0,1}, {-1,0}, {0,-1}};
void dfs(int x, int y) {
    floor[x][y] = true;
    for (auto m : moves) { 
        if (isValid(x + m.first, y + m.second)) {
            dfs(x + m.first, y + m.second);
        }
    }
}


void solve() {
    cin >> n >> m;

    floor.resize(n);

    for (int i = 0; i < n; ++i) {
        floor[i].resize(m);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c; cin >> c;
            if (c == '#') {
                floor[i][j] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!floor[i][j]) {
                dfs(i, j);
                res++;
            }
        }
    }

    cout << res;
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