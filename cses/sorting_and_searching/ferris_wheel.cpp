#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    ll x; cin >> x;

    vector<ll> children(n);
    for (int i = 0; i < n; ++i) {
        ll w; cin >> w;
        children[i] = w;
    }
    sort(children.begin(), children.end());

    int res = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        // 2 3 7 9
        if (children[r] + children[l] <= x) {
            l++;
            r--;
        }
        else {
            r--;
        }
        res++;
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