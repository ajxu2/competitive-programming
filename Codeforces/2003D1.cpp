// created: 12-22-2024 Sun 12:20 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, m; cin >> n >> m;
    V<V<int>> a(n);
    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        a[i].resize(l);
        for (int j = 0; j < l; j++) cin >> a[i][j];
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        sort(begin(a[i]), end(a[i]));
        int l = ssize(a[i]);
        // find second mex
        V<int> excluded;
        int ptr = 0;
        for (int j = 0; j < l + 2; j++) {
            while (ptr < l && a[i][ptr] < j) ptr++;
            if (ptr == l || a[i][ptr] != j) excluded.push_back(j);
        }
        mx = max(mx, excluded[1]);
    }
    if (m < mx) cout << (ll)(m + 1) * mx << '\n';
    else cout << (ll)mx * mx + (ll)(mx + m) * (m - mx + 1) / 2 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
