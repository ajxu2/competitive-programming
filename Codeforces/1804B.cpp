// created: 03-12-2023 Sun 09:39 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, k, d, w; cin >> n >> k >> d >> w;
    V<int> a(n);
    for (int& i : a) cin >> i;
    int ans = 0, st = 0, en = 0;
    while (st < n) {
        while (en < n && en - st + 1 <= k && a[en] - (a[st] + w) <= d) en++;
        st = en; ans++;
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
