// created: 11-24-2022 Thu 03:50 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    vector<vector<bool>> adj(n, vector<bool>(n, false)); // adj[i][j] if cow i could get gift j
    for (int i = 0; i < n; i++) {
        for (int j : a[i]) {
            adj[i][j] = true;
            if (i == j) break;
        }
    }
    vector<ll> ans(1<<n, 0);
    ans[0] = 1;
    vector<vector<ll>> dp(1<<n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) dp[1<<i][i] = 1;
    for (int i = 0; i < n; i++) { // MSB
        for (int mask = (1<<i); mask < (1<<(i+1)); mask++) {
            for (int last = 0; last <= i; last++) {
                if (mask&(1<<last)) {
                    // either continue the cycle
                    for (int k = 0; k < i; k++) {
                        // can we give gift k to cow last?
                        if (!(mask&(1<<k)) && adj[last][k]) dp[mask^(1<<k)][k] += dp[mask][last];
                    }
                    // or complete it
                    if (adj[last][i]) ans[mask] += dp[mask][last];
                }
            }
            for (int last = i+1; last < n; last++) {
                // if we want to start a new cycle...
                dp[mask^(1<<last)][last] += ans[mask];
            }
        }
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        string s; cin >> s;
        int k = 0;
        for (int j = 0; j < n; j++) if (s[j] == 'G') k += (1<<j);
        cout << ans[k] * ans[(1<<n)-1-k] << "\n";
    }
    return 0;
}
