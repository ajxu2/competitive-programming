// created: 10-23-2023 Mon 10:20 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, a, b; cin >> n >> a >> b;
    V<V<double>> dp(n, V<double>(6*n+1, 0));
    for (int i = 1; i <= 6; i++) dp[0][i] = 1. / 6;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= 6*n; j++) {
            for (int k = 1; k <= 6; k++) {
                if (j - k < 0) continue;
                dp[i][j] += dp[i-1][j-k] / 6;
            }
        }
    }
    double sum = 0;
    for (int i = a; i <= b; i++) sum += dp[n-1][i];
    cout << fixed << setprecision(6) << sum << "\n";
    return 0;
}
