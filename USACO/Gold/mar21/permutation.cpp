// created: 06-18-2023 Sun 04:44 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

const int MOD = 1'000'000'007;

struct Pt {
    int x, y;
    Pt(int x, int y): x(x), y(y) {}
    int cross(Pt a) { return x * a.y - y * a.x; }
    int cross(Pt a, Pt b) {
        Pt one(a.x - x, a.y - y);
        Pt two(b.x - x, b.y - y);
        return one.cross(two);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<Pt> a(n, Pt(0, 0));
    for (Pt& i : a) cin >> i.x >> i.y;
    V<V<V<V<ll>>>> dp(n+1, V<V<V<ll>>>(n, V<V<ll>>(n, V<ll>(n, 0))));
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                dp[3][i][j][k] = 6;
            }
        }
    }
    for (int i = 3; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                for (int l = k+1; l < n; l++) {
                    int inside = n-i;
                    for (int m = 0; m < n; m++) {
                        if (m == j || m == k || m == l) continue;
                        // check if m on different side
                        array<bool, 3> diff = {0, 0, 0};
                        if ((a[m].cross(a[k], a[l]) > 0) ^ (a[j].cross(a[k], a[l]) > 0)) diff[0] = 1;
                        if ((a[m].cross(a[l], a[j]) > 0) ^ (a[k].cross(a[l], a[j]) > 0)) diff[1] = 1;
                        if ((a[m].cross(a[j], a[k]) > 0) ^ (a[l].cross(a[j], a[k]) > 0)) diff[2] = 1;
                        int cnt = 0;
                        for (int o = 0; o < 3; o++) if (diff[o]) cnt++;
                        if (cnt == 2) {
                            // can connect
                            array<int, 3> nxt = {j, k, l};
                            for (int o = 0; o < 3; o++) if (!diff[o]) nxt[o] = m;
                            sort(nxt.begin(), nxt.end());
                            dp[i+1][nxt[0]][nxt[1]][nxt[2]] += dp[i][j][k][l];
                            dp[i+1][nxt[0]][nxt[1]][nxt[2]] %= MOD;
                            inside--;
                        } else if (cnt == 1) inside--;
                    }
                    dp[i+1][j][k][l] += dp[i][j][k][l] * inside;
                    dp[i+1][j][k][l] %= MOD;
                }
            }
        }
    }
    ll ans = 0;
    for (int j = 0; j < n; j++) {
        for (int k = j+1; k < n; k++) {
            for (int l = k+1; l < n; l++) {
                ans += dp[n][j][k][l];
                ans %= MOD;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

