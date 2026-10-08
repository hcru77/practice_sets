#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < m ; ++i) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> parents(n + 1); // Keep track of where node came from
    vector<int> dist(n + 1, 1e9); // grab the shortest distance 


    queue<int> q;
    q.push(1);
    parents[1] = 1;
    dist[1] = 1;
    

    // 1 -- 2, 3, 4
    // 2 -- 1
    // 3 -- 1, 5
    // 4 - 1

    // perform bfs
    while (!q.empty()) {
        int temp = q.front();
        q.pop();

        for (int e : edges[temp]) {
            if (dist[e] > dist[temp] + 1) {
                parents[e] = temp;
                dist[e] = dist[temp] + 1;
                q.push(e);
            }
        }
    }

    if (dist[n] == 1e9) {
        cout << "IMPOSSIBLE";
    }
    else {
        vector<int> res;
        int j = n;
        for (int i = 0; i < dist[n]; ++i) {
            res.push_back(j);
            j = parents[j];
        }
        reverse(res.begin(), res.end());
        cout << dist[n] << endl;
        for (int i : res)
            cout << i << " ";
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