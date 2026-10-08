#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n; cin >> n;

    int x;
    vector<int> arr{};
    while (cin >> x){
        arr.push_back(x);
    }

    long long moves(0);
    for(int i = 1; i < n; ++i) {
        if (arr[i] >= arr[i - 1]){
            continue;
        }
        moves += (arr[i-1] - arr[i]);
        arr[i] = arr[i - 1];
    }
    cout << moves;
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