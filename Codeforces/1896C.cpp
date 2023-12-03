// created: 11-25-2023 Sat 09:58 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n, x; cin >> n >> x;
    V<array<int, 2>> a(n);
    V<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    for (int& i : b) cin >> i;
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    V<int> p(n+1, 0);
    for (int i = 0; i < n; i++) {
        array<int, 2> search = {b[i], INT_MAX};
        int j = upper_bound(begin(a), end(a), search) - begin(a);
        int l = j - i, r = n - 1 - i;
        if (l < 0) {
            p[n+l]++; p[n]--;
            p[0]++; p[r+1]--;
        } else {
            p[l]++; p[r+1]--;
        }
    }
    for (int i = 1; i <= n; i++) p[i] += p[i-1];
    int ans = -1;
    for (int i = 0; i < n; i++) if (p[i] == x) ans = i;
    if (ans == -1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    V<int> ansv(n);
    for (int i = 0; i < n; i++) ansv[a[(i+ans)%n][1]] = b[i];
    for (int i = 0; i < n; i++) cout << ansv[i] << " \n"[i == n-1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
