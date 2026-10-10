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
    for (int k = 0; k < t; k++) {

        int n; cin >> n;
        vector<int> templt(n);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            templt[i] = x;
        }
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            string cur;
            cin >> cur;

            if (cur.size() != n) {
                std::cout << "NO\n";
                continue;
            }
            
            bool valid = true;
            unordered_map<char, int> ctoi;
            unordered_map<int, char> itoc;

            for (int c = 0; c < n; c++) {
                auto it = ctoi.find(cur[c]);
                auto it2 = itoc.find(templt[c]);
                if (it == ctoi.end() && it2 == itoc.end()) {
                    ctoi[cur[c]] = templt[c];
                    itoc[templt[c]] = cur[c];
                }
                else if (ctoi[cur[c]] != templt[c] || itoc[templt[c]] != cur[c]){
                    std::cout << "NO\n";
                    valid = false;
                    break;
                }
            }
            if (valid)
                std::cout << "YES\n";
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