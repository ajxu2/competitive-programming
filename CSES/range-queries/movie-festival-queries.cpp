// created: 05-27-2025 Tue 04:04 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MX = 1'000'000;
const int LOGMX = 21;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    V<V<int>> a(MX); // end times of movies that start at some time
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r; l--, r--;
        a[l].push_back(r);
    }
    V<int> nxt(MX); // earliest time to finish 1 more movie
    int mn = MX;
    for (int i = MX - 1; i >= 0; i--) {
        for (int j : a[i])
            mn = min(mn, j);
        nxt[i] = mn;
    }
    // compute binary lifting on nxt
    V<V<int>> lift(LOGMX, V<int>(MX));
    lift[0] = nxt;
    for (int i = 1; i < LOGMX; i++) {
        for (int j = 0; j < MX; j++) {
            if (lift[i-1][j] == MX)
                lift[i][j] = MX;
            else
                lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }
    // answer queries
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        int ans = 0;
        for (int i = LOGMX - 1; i >= 0; i--) {
            if (lift[i][l] <= r) {
                ans += 1 << i;
                l = lift[i][l];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
