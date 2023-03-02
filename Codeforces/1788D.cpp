#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

int main() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    // key idea: ans for range = # of LR + 1
    // count how many times each pair can be an LR
    V<int> pow2(n+1, 1);
    for (int i = 1; i <= n; i++) pow2[i] = pow2[i-1] * 2 % MOD;
    int ans = pow2[n] - n - 1; // # subsets length >=2
    for (int i = 1; i < n-1; i++) {
        for (int j = i+1; j < n-1; j++) {
            int diff = a[j] - a[i];
            int add = pow2[n-(j-i+1)]; // not containing middle
            int l = lower_bound(a.begin(), a.end(), a[i] - diff) - a.begin();
            int r = lower_bound(a.begin(), a.end(), a[j] + diff) - a.begin() - 1;
            // must contain 1 element in [l, i-1] and 1 in [j+1, r]
            add = (add - pow2[n-(j-l+1)]) % MOD; // none in [l, i-1]
            add = (add - pow2[n-(r-i+1)]) % MOD; // none in [j+1, r]
            add = (add + pow2[n-(r-l+1)]) % MOD; // PIE
            ans = (ans + add) % MOD;
        }
    }
    cout << (ans < 0 ? ans + MOD : ans) << "\n";
    return 0;
}
