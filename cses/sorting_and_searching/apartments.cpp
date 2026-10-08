#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
void solve() {
    int n; cin >> n;
    int m; cin >> m;
    int k; cin >> k;


    vector<ll> apL(n);
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        apL[i] = x;
    }

    vector<ll> apT(m);
    for (int i = 0; i < m; ++i) {
        ll x; cin >> x;
        apT[i] = x;
    }

    sort(apL.begin(), apL.end());
    sort(apT.begin(), apT.end());

    int res = 0;
    int l = 0, t = 0;

    while (l < n && t < m) {
        if (apT[t] >= apL[l] - k && apT[t] <= apL[l] + k ) {
            res += 1;
            l++;
            t++;
        }
        else if (apL[l] - k > apT[t]) {
            t++;
        }
        else {
            l++;
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