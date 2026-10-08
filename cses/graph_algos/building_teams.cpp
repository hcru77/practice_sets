#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;
using ll = long long;


bool bfs(int st, vector<int>& team, vector<vector<int>>& graph) {
    queue<int> q;
    q.push(st);
    team[st] = 1;

    while (!q.empty()) {
        int curr = q.front(); q.pop();
        
        for (auto child : graph[curr]) {
            if (team[child] == -1) {
                team[child] = 3 - team[curr];
                q.push(child);
            }
            else if (team[child] == team[curr]) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> team(n + 1, -1);

    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // loop through all the individuals and call bfs if it hasnt been called on them (team == -1)
    for(int i = 1; i < n + 1; ++i) {
        if (team[i] == -1) {
            if (!bfs(i, team, graph)) {
                cout << "IMPOSSIBLE";
                return;
            }
        }
    }

    for (int i = 1; i < n + 1; ++i) {
        cout << team[i] << " ";
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