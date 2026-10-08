#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n + 1);
    // loop through all the roads and begin to make all the connected components
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<bool> vis(n + 1, false);
    auto dfs = [&](auto &&self, int curr) -> void { // auto &&self is reference to its own closure object
        vis[curr] = true;                       // void is optional, compiler can deduce
        for (auto c : edges[curr]) {
            if (!vis[c]) {
                self(self, c);
            }
        }
    };

    vector<int> res;
    for (int i = 1; i < n + 1; ++i) {
        if (!vis[i]) {
            res.push_back(i);
            dfs(dfs, i);
        }
    }

    int t = res.size();
    cout << t - 1 << endl;
    for (int i = 0; i < t - 1; ++i) {
        cout << res[i] << " " << res[i + 1] << "\n";
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