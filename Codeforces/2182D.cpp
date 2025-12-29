// created: 12-29-2025 Mon 08:59 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998'244'353;

void solve() {
    int n, x; cin >> n >> x;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    int max = -1, cnt_max = 0;
    for (int i : a) {
        if (i > max) {
            max = i;
            cnt_max = 1;
        } else if (i == max) {
            cnt_max++;
        }
    }
    int sum = accumulate(begin(a), end(a), 0);
    ll ans = 0;
    for (int i = cnt_max - 1; i < n; i++) {
        // last max at i
        int needed = max * (i + 1) + (max - 1) * (n - i - 1) - sum;
        if (needed <= x) {
            ll add = cnt_max;
            for (int j = 0; j < cnt_max - 1; j++)
                (add *= i - j) %= MOD;
            for (int j = 1; j <= n - cnt_max; j++)
                (add *= j) %= MOD;
            (ans += add) %= MOD;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
