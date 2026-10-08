#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    int m; cin >> m;

    multiset<ll> tks;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        tks.insert(x);
    }
    
    for (int i = 0; i < m; ++i) {
        ll x; cin >> x;
        auto it = tks.upper_bound(x);
        if (it == tks.begin()) {
            cout << "-1" << endl;
        }
        else {
            it--;
            cout << *it << endl;
            tks.erase(it);
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