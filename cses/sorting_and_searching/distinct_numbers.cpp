#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        ll c; cin >> c;
        v[i] = c;
    }
    sort(v.begin(), v.end());

    auto pos = unique(v.begin(), v.end());
    cout << pos - v.begin() << endl;
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