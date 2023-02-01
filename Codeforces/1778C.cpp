// created: 02-01-2023 Wed 09:38 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    // i'm praying so hard that this fits in TL
    // update: it did not fit in TL
    int n, k; cin >> n >> k;
    string a, b; cin >> a >> b;
    map<char, int> m; int cnt = 0;
    for (char i : a) {
        if (!m.count(i)) {
            m[i] = cnt; cnt++;
        }
    }
    V<int> nums(n);
    for (int i = 0; i < n; i++) nums[i] = m[a[i]];
    ll ans = 0;
    for (int mask = 0; mask < (1<<cnt); mask++) {
        int bruh = 0;
        for (int i = 0; i < cnt; i++) if (mask&(1<<i)) bruh++;
        if (bruh != min(k, cnt)) continue;
        bruh = 1;
        ll bruh2 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i] || mask&(1<<nums[i])) {
                bruh2 += bruh; bruh++;
            } else bruh = 1;
        }
        ans = max(ans, bruh2);
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
