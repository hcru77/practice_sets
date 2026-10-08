#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n; cin >> n;
    if (n == 1){
        cout << 1;
        return;
    }
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION \n";
        return;
    }

    int cur(2);
    for (int i = 0; i < n; ++i) {
        if (i == (n / 2)){
            cur = 1;
        }
        cout << cur << " ";
        cur += 2;
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