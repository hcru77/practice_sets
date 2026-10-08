#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

void solve() {
    ll n; cin >> n;

    vector<ll> s1;
    vector<ll> s2;

    if ( (n * (n + 1) / 2) % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    else {
        if (n % 2 == 1) {
            n--;
        }
         // n = 6
        for (ll i = 1; i < (n / 2) + 1; ++i) {
          if (i % 2 == 0) {
            s1.push_back(i);
            s1.push_back(n - i + 1);
          }
          else {
            s2.push_back(i);
            s2.push_back(n - i + 1);
          }
        }

        if (s1.size() < s2.size()) {
            s1.push_back(n + 1);
        }
    }
    cout << "YES" << endl;
    cout << s1.size() << endl;
    for (int i : s1) {
        cout << i << " ";
    }
    cout << endl;
    cout << s2.size() << endl;
    for (int i : s2) {
        cout << i << " ";
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