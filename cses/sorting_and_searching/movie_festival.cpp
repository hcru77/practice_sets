#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<pair<int, int>> times;
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        times.push_back({a, b});
    }
    sort(times.begin(), times.end());

    pair<int, int> last{0, 0};
    int res = 0;
    for (auto p : times) {
        if (p.first >= last.second) { 
            res++;
            last = p;
        }
        else {
            if (p.second < last.second) {
                last = p;
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