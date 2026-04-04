// created: 04-04-2026 Sat 08:37 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998'244'353;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    V<V<int>> fac(n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            fac[j].push_back(i);
    ll sum_b = accumulate(begin(b), end(b), 0LL) % MOD;
    ll ans = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        (sum += sum_b) %= MOD;
        for (int j : fac[i]) {
            if (j <= m) {
                (sum -= (ll)j * b[j]) %= MOD;
                if (sum < 0)
                    sum += MOD;
            }
        }
        (ans += a[i] * sum) %= MOD;
    }
    cout << ans << '\n';
    return 0;
}
