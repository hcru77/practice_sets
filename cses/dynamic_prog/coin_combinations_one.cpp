#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    int x; cin >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1);
    dp[0] = 1;

    for (int i = 1; i < x + 1; ++i) {
        for (int j = 0; j < n; ++j) {
            if (coins[j] <= i) {
                dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
            }
        }
    }
    cout << dp[x];
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