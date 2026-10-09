#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

// arithmetic series formula
ll calcSum(ll start, ll end) {
    ll sum = (end - start + 1) * (start + end) / 2;
    return sum;
}

void solve() {
    int t; cin >> t;
    for (int k = 0; k < t; k++) {

        /*
            Indices divisible by both x and y are irrelevant since they will be added to left 
            sum of permutations and subracted in right sum of permutations

            We want to have max values be in indices divisible by x and min values be in indices divisible by y
        
        */

        ll n, x, y; cin >> n >> x >> y;

        ll purp = n / lcm(x, y);

        ll red = n / x - purp;
        ll blue = n / y - purp;

        ll lhs = calcSum(n - red + 1, n);
        ll rhs = calcSum(1LL, blue);
        
        cout << lhs - rhs << "\n";
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