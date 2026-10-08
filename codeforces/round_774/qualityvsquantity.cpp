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

    for (int i = 0; i < t; i ++) {
        int n; cin >> n;

        int vec[n];
        for (int j = 0; j < n; j++) {
            cin >> vec[j];
        }
        sort(vec, vec + n);

        
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