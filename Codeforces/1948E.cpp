// created: 12-15-2024 Sun 04:47 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    // key idea: for any n, we can set the a1, a2, ..., an
    // such that for all i, j, |i-j|+|ai-aj| <= n
    int n, k; cin >> n >> k;
    int q = (n + k - 1) / k;
    for (int i = 0; i < n; i++) {
        int sz = i / k == q - 1 ? ((n - 1) % k) + 1 : k;
        cout << (i % k + sz / 2) % sz + (i / k * k) + 1 << " \n"[i == n-1];
    }
    cout << q << '\n';
    for (int i = 0; i < n; i++) {
        cout << i / k + 1 << " \n"[i == n-1];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
