// created: 01-24-2026 Sat 07:11 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<int> deg(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        deg[u]++; deg[v]++;
    }
    for (int i = 0; i < n; i++) {
        int other = n - 1 - deg[i];
        cout << (ll)other * (other - 1) * (other - 2) / 6 << ' ';
    }
    cout << '\n';
    return 0;
}
