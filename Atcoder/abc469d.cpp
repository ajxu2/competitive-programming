// created: 08-01-2026 Sat 11:56 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<array<int, 2>> a(m);
    for (auto& [u, v] : a)
        cin >> u >> v, u--, v--;
    set<array<int, 2>> ans;
    auto ins = [&](int i, int j) -> void {
        if (i == j)
            return;
        if (i > j)
            swap(i, j);
        ans.insert({i, j});
    };
    for (int i = 0; i < 2; i++) {
        // put a[0][i] in the VC, and go from there
        int u = a[0][i];
        V<array<int, 2>> b;
        for (auto [x, y] : a)
            if (x != u && y != u)
                b.push_back({x, y});
        if (b.empty()) {
            for (int j = 0; j < n; j++)
                ins(u, j);
            continue;
        }
        for (int j = 0; j < 2; j++) {
            int v = b[0][j]; // diff from u
            bool good = true;
            for (auto [x, y] : b)
                if (x != v && y != v)
                    good = false;
            if (good)
                ins(u, v);
        }
    }
    cout << ssize(ans) << '\n';
    return 0;
}
