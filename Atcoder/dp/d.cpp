// created: 01-22-2026 Thu 12:55 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, t; cin >> n >> t;
    V<int> w(n), v(n);
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    V<ll> dp(t + 1, -INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = t; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << *max_element(begin(dp), end(dp)) << '\n';
    return 0;
}
