// created: 05-20-2025 Tue 11:25 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MAXN = 20;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    array<ll, MAXN + 1> fact;
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fact[i] = fact[i-1] * i;
    int T; cin >> T;
    while (T--) {
        int t; cin >> t;
        if (t == 1) {
            int n; ll k; cin >> n >> k; k--;
            V<int> remaining(n);
            iota(begin(remaining), end(remaining), 1);
            for (int i = 0; i < n; i++) {
                int idx = k / fact[n-i-1];
                cout << remaining[idx] << ' ';
                remaining.erase(begin(remaining) + idx);
                k %= fact[n-i-1];
            }
            cout << '\n';
        } else {
            int n; cin >> n;
            V<int> remaining(n);
            iota(begin(remaining), end(remaining), 1);
            ll ans = 1;
            for (int i = 0; i < n; i++) {
                int x; cin >> x;
                auto it = lower_bound(begin(remaining), end(remaining), x);
                ans += (it - begin(remaining)) * fact[n-i-1];
                remaining.erase(it);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
