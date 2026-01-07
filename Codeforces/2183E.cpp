// created: 01-07-2026 Wed 11:43 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998'244'353;
void mod_add(int& a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

void solve() {
    int n, m; cin >> n >> m;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    // only way for a sequence to be good: a1 = 1, and a(i+1)-ai | ai for all i
    V<V<int>> factors(m + 1);
    for (int i = 1; i <= m; i++)
        for (int j = i; j <= m; j += i)
            factors[j].push_back(i);
    if (a[0] > 1) {
        cout << "0\n";
        return;
    }
    V<V<int>> dp(n, V<int>(m + 1, 0)); // fill in [0, i] such that a[i] = j
    dp[0][1] = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k : factors[j]) {
                int nxt = j + k;
                if (nxt <= m && (a[i + 1] == 0 || a[i + 1] == nxt))
                    mod_add(dp[i + 1][nxt], dp[i][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
        mod_add(ans, dp[n - 1][i]);
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
