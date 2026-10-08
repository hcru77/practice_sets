#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<pair<int, int>> times;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        int y; cin >> y;
        times.push_back({x, 1});
        times.push_back({y, -1});
    }

    sort(times.begin(), times.end());


    int maxx = 0;
    int curr = 0;
    for (auto it : times) {
        if (it.second == 1) {
            curr++;
        }
        else {
            curr--;
        }
        maxx = max(curr, maxx);
    }
    cout << maxx;

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