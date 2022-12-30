// created: 12-30-2022 Fri 08:46 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, k; cin >> n >> k;
    V<int> a(n);
    if (n == 1) {
        cout << "1\n";
        return;
    }
    a[0] = n; a[1] = 1;
    for (int i = 2; i < n; i += 2) a[i] = a[i-2] - 1;
    for (int i = 3; i < n; i += 2) a[i] = a[i-2] + 1;
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n-1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
