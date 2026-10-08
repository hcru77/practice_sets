#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> cs(n); 
    for (int i = 0; i < n; ++i) {
        cin >> cs[i];
    }

    vector<int> dp(x + 1, x + 1);
    dp[0] = 0;
    for (int i = 1; i < x + 1; ++i) {
        for (int c : cs) {
            if (c <= i) {
                if (dp[i - c] != x + 1)
                    dp[i] = min(dp[i], 1 + dp[i - c]);
            }
        }
    }
    if (dp[x] == x + 1) {
        cout << -1;
    }
    else {
        cout << dp[x];
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