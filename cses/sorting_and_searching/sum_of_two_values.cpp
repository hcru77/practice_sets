#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    int t; cin >> t;

    vector<int> v(n);

    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    unordered_map<int, int> trk;
    for(int i = 0; i < n; ++i) {
        int c = v[i];
        if (c > t) {
            continue;
        }
        if (trk.contains(t - c)) {
            cout << trk[t-c] + 1 << " " << i + 1;
            return;
        }
        else {
            trk[c] = i;
        }
    }
    cout << "IMPOSSIBLE";

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