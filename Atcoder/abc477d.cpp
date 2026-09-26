// created: 09-26-2026 Sat 08:50 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    V<pair<int, char>> queries; // (timestamp, color)
    V<V<array<int, 2>>> a(n); // intervals when active
    V<int> lst(n, 0);
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x; x--;
            if (lst[x] == -1) {
                lst[x] = i;
            } else {
                a[x].push_back({lst[x], i});
                lst[x] = -1;
            }
        } else {
            char c; cin >> c;
            queries.push_back({i, c});
        }
    }
    for (int i = 0; i < n; i++)
        if (lst[i] != -1)
            a[i].push_back({lst[i], q});
    for (int i = 0; i < n; i++) {
        // check color of i
        char cur = 'a';
        for (auto [l, r] : a[i]) {
            auto it = upper_bound(begin(queries), end(queries), pair<int, char>{r, 'x'});
            if (it != begin(queries)) {
                it--;
                auto [t, c] = *it;
                if (t >= l)
                    cur = c;
            }
        }
        cout << cur;
    }
    cout << '\n';
    return 0;
}
