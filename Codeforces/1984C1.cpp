// created: 06-09-2024 Sun 10:00 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    V<ll> pre(n), suf(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++) pre[i] = pre[i-1] + a[i];
    suf[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) suf[i] = suf[i+1] + a[i];
    ll ans = abs(pre[n-1]);
    for (int i = 0; i < n-1; i++) ans = max(ans, abs(pre[i]) + suf[i+1]);
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
