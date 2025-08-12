// created: 08-11-2025 Mon 07:30 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, k; cin >> n >> k;
    // erdos szekeres my beloved
    if (k * k < n) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    V<int> ans(n);
    iota(begin(ans), end(ans), 1);
    for (int i = 0; i < n; i += k) {
        int j = min(n, i + k);
        reverse(begin(ans) + i, begin(ans) + j);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n-1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
