// created: 10-23-2023 Mon 10:12 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    V<int> a(k);
    for (int& i : a) cin >> i;
    V<bool> dp(n+1); dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j : a) {
            if (i - j < 0) continue;
            dp[i] = dp[i] | !dp[i-j];
        }
    }
    for (int i = 1; i <= n; i++) cout << (dp[i] ? 'W' : 'L');
    cout << "\n";
    return 0;
}
