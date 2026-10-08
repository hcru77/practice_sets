#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    for (long long k = 1; k < n + 1; ++k) {
        cout << ((k * k) * (k * k - 1) / 2) - (4 * (k - 2) * (k - 1)) << endl;
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