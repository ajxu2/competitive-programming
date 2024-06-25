// created: 06-25-2024 Tue 10:33 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    V<V<int>> a(n, V<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    V<V<int>> bruh(n, V<int>(m));
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            bruh[i][j] = s[j] == '1' ? 1 : -1;
            sum += a[i][j] * bruh[i][j];
        }
    }
    sum = abs(sum);
    if (sum == 0) {
        cout << "YES\n";
        return;
    }
    V<V<int>> psum(n+1, V<int>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            psum[i][j] = psum[i][j-1] + psum[i-1][j] - psum[i-1][j-1] + bruh[i-1][j-1];
        }
    }
    int g = 0;
    for (int i = k; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            g = gcd(g, abs(psum[i][j] - psum[i-k][j] - psum[i][j-k] + psum[i-k][j-k]));
        }
    }
    if (g != 0 && sum % g == 0) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
