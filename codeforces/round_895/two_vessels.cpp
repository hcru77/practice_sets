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
    for (int i = 0; i < t; i++) {
        int a, b, c; cin >> a >> b >> c;
        
        int diff = abs(a - b);
        int divnd = (diff + 1) / 2;
        int res = (divnd + c - 1) / c;

        cout << res << "\n";
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