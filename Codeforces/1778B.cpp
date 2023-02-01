// created: 02-01-2023 Wed 08:50 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, m, d; cin >> n >> m >> d;
    V<int> pos(n+1), p(m);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        pos[a] = i;
    }
    for (int& i : p) cin >> i;
    bool ngood = true;
    for (int i = 0; i < m-1; i++) {
        if (!(pos[p[i]] < pos[p[i+1]] && pos[p[i+1]] <= pos[p[i]] + d)) ngood = false;
    }
    if (!ngood) {
        cout << "0\n";
        return;
    }
    int ans = 1e9;
    for (int i = 0; i < m-1; i++) {
        ans = min(ans, pos[p[i+1]] - pos[p[i]]);
        if (d < n-1) ans = min(ans, d + 1 - (pos[p[i+1]] - pos[p[i]]));
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
