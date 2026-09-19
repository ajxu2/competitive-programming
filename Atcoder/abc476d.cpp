// created: 09-19-2026 Sat 11:29 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    ll x, y; cin >> x >> y;
    V<ll> a(n), b(m);
    for (ll& i : a)
        cin >> i;
    for (ll& i : b)
        cin >> i;
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    V<ll> pa(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pa[i] = pa[i - 1] + a[i - 1];
    ll balance = x + k * y;
    int a_can_buy = n;
    while (a_can_buy >= 0 && pa[a_can_buy] > balance)
        a_can_buy--;
    int ans = a_can_buy;
    ll k_used = 0;
    for (int i = 0; i < m; i++) {
        k_used += (b[i] + k - 1) / k;
        balance -= b[i];
        if (k_used > y || balance < 0)
            break;
        while (a_can_buy >= 0 && pa[a_can_buy] > balance)
            a_can_buy--;
        ans = max(ans, i + 1 + a_can_buy);
    }
    cout << ans << '\n';
    return 0;
}
