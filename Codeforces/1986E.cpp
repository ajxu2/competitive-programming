// created: 06-23-2024 Sun 10:21 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, k; cin >> n >> k;
    V<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][1];
        a[i][0] = a[i][1] % k;
    }
    sort(begin(a), end(a));
    int odd = 0, ptr = 0; ll ans = 0;
    while (ptr < n) {
        int cur = a[ptr][0];
        V<int> stuff;
        while (ptr < n && a[ptr][0] == cur) {
            stuff.push_back(a[ptr][1]);
            ptr++;
        }
        if (ssize(stuff) % 2 == 1) {
            odd++;
            int s = ssize(stuff);
            if (s == 1) continue;
            V<ll> pref(s), suf(s);
            pref[1] = (stuff[1] - stuff[0]) / k;
            for (int i = 3; i < s; i += 2) pref[i] = pref[i-2] + (stuff[i] - stuff[i-1]) / k;
            suf[s-2] = (stuff[s-1] - stuff[s-2]) / k;
            for (int i = s-4; i >= 0; i -= 2) suf[i] = suf[i+2] + (stuff[i+1] - stuff[i]) / k;
            ll add = min(suf[1], pref[s-2]);
            for (int i = 1; i < s-2; i += 2) add = min(add, pref[i] + suf[i+2]);
            ans += add;
        } else {
            for (int i = 0; i < ssize(stuff); i += 2) ans += (stuff[i+1] - stuff[i]) / k;
        }
    }
    if (odd > 1) cout << "-1\n";
    else cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
