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
    vector<int> vec(n);
    for(int i = 0; i < n; ++i) {
        cin >> vec[i];
    }    

    ll curr = vec[0], maxx = vec[0];
    for(int i = 1; i < n; ++i) {
        if(curr < 0) {
            curr = 0;
        }
        else {
            maxx = max(curr, maxx);
        }
        curr += vec[i];
    }
    maxx = max(maxx, curr);
    cout << maxx;
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