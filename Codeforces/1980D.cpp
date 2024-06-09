// created: 06-08-2024 Sat 10:25 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    V<int> pre(n), suf(n);
    pre[0] = 0;
    for (int i = 1; i < n; i++) {
        int g = gcd(a[i], a[i-1]);
        if (pre[i-1] == -1 || g < pre[i-1]) pre[i] = -1;
        else pre[i] = g;
    }
    suf[n-1] = numeric_limits<int>::max();
    for (int i = n-2; i >= 0; i--) {
        int g = gcd(a[i], a[i+1]);
        if (suf[i+1] == -1 || g > suf[i+1]) suf[i] = -1;
        else suf[i] = g;
    }
    bool ok = suf[1] != -1 || pre[n-2] != -1;
    for (int i = 1; i < n-1; i++) {
        int g = gcd(a[i-1], a[i+1]);
        ok |= pre[i-1] != -1 && suf[i+1] != -1 && pre[i-1] <= g && g <= suf[i+1];
    }
    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
