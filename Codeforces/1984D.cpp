// created: 06-09-2024 Sun 11:52 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

const int MOD = 1'000'000'007;

void solve() {
    string s; cin >> s;
    int n = sz(s);
    array<ll, 2> B;
    B[0] = chrono::steady_clock::now().time_since_epoch().count() % MOD;
    B[1] = (B[0] + 69) % MOD;
    array<V<ll>, 2> pow, hsh;
    for (int i = 0; i < 2; i++) {
        pow[i].resize(n); pow[i][0] = 1;
        for (int j = 1; j < n; j++) pow[i][j] = pow[i][j-1] * B[i] % MOD;
        hsh[i].resize(n); hsh[i][0] = s[0];
        for (int j = 1; j < n; j++) hsh[i][j] = (hsh[i][j-1] * B[i] + s[j]) % MOD;
    }
    auto substr = [&](int i, int j) -> array<ll, 2> {
        j = min(i + j, n);
        if (i == 0) return {hsh[0][j-1], hsh[1][j-1]};
        array<ll, 2> res;
        for (int k = 0; k < 2; k++) {
            ll tmp = (hsh[k][j-1] - pow[k][j-i] * hsh[k][i-1]) % MOD;
            res[k] = tmp < 0 ? tmp + MOD : tmp;
        }
        return res;
    };
    V<int> nxt(n); nxt[n-1] = n;
    for (int i = n-2; i >= 0; i--) {
        if (s[i+1] != 'a') nxt[i] = i+1;
        else nxt[i] = nxt[i+1];
    }
    if (s[0] == 'a' && nxt[0] == n) {
        cout << n - 1 << '\n';
        return;
    }
    int start = s[0] == 'a' ? nxt[0] : 0;
    ll ans = 0;
    for (int len = 1; len <= n - start; len++) {
        array<ll, 2> src = substr(start, len);
        int cur = start, cnt = start, pre = -1;
        bool ok = true;
        while (cur < n) {
            if (cur + len > n) {
                ok = false;
                break;
            }
            ok &= substr(cur, len) == src;
            cnt = min(cnt, cur - pre - 1);
            pre = cur + len - 1; cur = nxt[pre];
        }
        if (ok) ans += cnt + 1;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
