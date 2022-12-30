// created: 12-30-2022 Fri 08:53 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<ll> a(n);
    for (ll& i : a) cin >> i;
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        if (a[i-1] == a[i]) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 2; i <= 50; i++) {
        V<int> b(n);
        for (int j = 0; j < n; j++) b[j] = a[j] % i;
        sort(b.begin(), b.end());
        V<bool> match(i, false);
        for (int j = 1; j < n; j++) if (b[j-1] == b[j]) match[b[j]] = true;
        bool ok = false;
        for (int j = 0; j < i; j++) ok |= !match[j];
        if (!ok) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
