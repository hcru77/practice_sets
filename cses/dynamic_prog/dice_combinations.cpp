#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;

    vector<ll> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < 7; ++j) {
            if ((i - j) < 0) {
                break;
            }
            dp[i] = (dp[i] + dp[i-j]) % mod;
        }
    }
    cout << dp[n];
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