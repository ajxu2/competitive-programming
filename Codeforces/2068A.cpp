// created: 04-12-2025 Sat 01:04 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<array<int, 2>> a(m);
    for (auto& [u, v] : a)
        cin >> u >> v;
    // strategy: for each pair (u, v), add u v 1 2 ... and ... 2 1 u v
    cout << "YES\n";
    cout << 2 * m << '\n';
    for (auto [u, v] : a) {
        cout << u << ' ' << v << ' ';
        for (int i = 1; i <= n; i++)
            if (i != u && i != v)
                cout << i << ' ';
        cout << '\n';
        for (int i = n; i >= 1; i--)
            if (i != u && i != v)
                cout << i << ' ';
        cout << u << ' ' << v << '\n';
    }
    return 0;
}
