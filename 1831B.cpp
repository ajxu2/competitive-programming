// created: 05-28-2023 Sun 09:39 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<int> a(n), b(n);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    V<int> al(2*n+1, 0), bl(2*n+1, 0);
    int cur = -1, len = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == cur) len++;
        else len = 1, cur = a[i];
        al[cur] = max(al[cur], len);
    }
    cur = -1, len = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] == cur) len++;
        else len = 1, cur = b[i];
        bl[cur] = max(bl[cur], len);
    }
    int ans = 0;
    for (int i = 1; i <= 2*n; i++) ans = max(ans, al[i] + bl[i]);
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
