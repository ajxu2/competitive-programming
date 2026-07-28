// created: 04-18-2026 Sat 08:14 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, m; cin >> n >> m;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    if (n == 1) {
        cout << "0\n";
        return;
    }
    V<int> b(n / 2);
    for (int i = 0; i < n / 2; i++) {
        b[i] = a[i] - a[n - 1 - i];
        if (b[i] < 0)
            b[i] += m;
    }
    V<int> diff;
    diff.push_back(b[0]);
    for (int i = 1; i < n / 2; i++) {
        int d = b[i] - b[i - 1];
        if (d < 0)
            d += m;
        diff.push_back(d);
    }
    diff.push_back((m - b.back()) % m);
    // need to turn diff into all zeros with a[i]++, a[j]--
    int sub = accumulate(begin(diff), end(diff), 0LL) / m;
    sort(begin(diff), end(diff));
    for (int i = 0; i < sub; i++)
        diff[ssize(diff) - 1 - i] -= m;
    ll ans = 0;
    for (int i : diff)
        ans += abs(i);
    ans >>= 1;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
