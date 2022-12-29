#include <bits/stdc++.h>
using namespace std;

template<class T> using V = vector<T>;

struct Cow {
    int p, c, x;
    bool operator<(const Cow& b) { return x < b.x; }
};

void ckmax(int& x, int y) { x = max(x, y); }

int main() {
    int n, a, b; cin >> n >> a >> b;
    V<Cow> c(n+1);
    for (int i = 1; i <= n; i++) cin >> c[i].p >> c[i].c >> c[i].x;
    sort(c.begin() + 1, c.end());
    // ewwwww, push dp
    V<V<int>> dpi(n+1, V<int>(b+1, 0)); // dpi[i][k] = dp[i][0][k]
    V<V<int>> dpm(n+1, V<int>(a+1, 0)); // dpm[i][j] = dp[i][j][b]
    for (int i = 0; i < n; i++) {
        for (int k = 0; k <= b; k++) {
            // bribe next guy with as many ice cream cones as possible
            int give = c[i+1].c * c[i+1].x;
            if (b - k < give) {
                // update dpm instead of dpi
                // since we are updating a state with b ice cream cones and nonzero moonies spent
                int cost = c[i+1].c - (b-k) / c[i+1].x;
                if (cost <= a) ckmax(dpm[i+1][cost], dpi[i][k] + c[i+1].p);
            } else ckmax(dpi[i+1][k+give], dpi[i][k] + c[i+1].p);
            // or just don't bribe next guy
            ckmax(dpi[i+1][k], dpi[i][k]);
        }
        for (int j = 0; j <= a; j++) {
            int cost = c[i+1].c;
            if (j + cost <= a) ckmax(dpm[i+1][j+cost], dpm[i][j] + c[i+1].p);
            ckmax(dpm[i+1][j], dpm[i][j]);
        }
    }
    int ans = 0;
    for (int k = 0; k <= b; k++) ckmax(ans, dpi[n][k]);
    for (int j = 0; j <= a; j++) ckmax(ans, dpm[n][j]);
    cout << ans << "\n";
    return 0;
}
