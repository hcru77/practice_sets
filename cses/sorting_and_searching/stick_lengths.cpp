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
    int n; cin >> n;
    vector<int> pVec(n);

    for (int i = 0; i < n; i++) {
        cin >> pVec[i];
    }

    sort(pVec.begin(), pVec.end());
    // ideal is found through the median in this case
    int x; x = pVec[n / 2];

    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += abs(pVec[i] - x);
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