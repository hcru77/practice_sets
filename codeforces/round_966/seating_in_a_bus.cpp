#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
    int t; cin >> t;
    for (int k = 0; k < t; k++) {

        int n; cin >> n;
        vector<int> bus(n);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            bus[i] = x;
        }

        bool followRule = true;
        int minn = bus[0];
        int maxx = bus[0];
        for (int p : bus) {
            if (abs(maxx - p) > 1 && abs(minn - p) > 1) {
                std::cout << "NO\n";
                followRule = false;
                break;
            }
            maxx = max(maxx, p);
            minn = min(minn, p);
        }
        if (followRule) {
            std::cout << "YES\n";
        }
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