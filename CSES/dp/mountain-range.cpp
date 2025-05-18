// created: 05-17-2025 Sat 09:30 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int floor_log(int x) {
    return 31 - countl_zero((unsigned)x);
}

struct SparseTable {
    int n;
    using T = int;
    V<V<T>> table;
    SparseTable(V<T> a) {
        n = ssize(a);
        table.resize(floor_log(n) + 1);
        table[0] = a;
        for (int i = 1; i <= floor_log(n); i++) {
            table[i].resize(n);
            for (int j = 0; j <= n - (1 << i); j++) {
                table[i][j] = max(table[i-1][j], table[i-1][j+(1<<(i-1))]);
            }
        }
    }
    T qry(int l, int r) { // half open [l, r)
        int lg = floor_log(r - l);
        return max(table[lg][l], table[lg][r-(1<<lg)]);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // idea: we always want to start from max element
    // then just solve with recursion
    int n; cin >> n;
    V<int> a(n);
    map<int, V<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    SparseTable st(a);
    auto solve = [&](auto&& self, int l, int r) -> int {
        if (l == r)
            return 0;
        int mx = st.qry(l, r);
        auto itl = lower_bound(begin(mp[mx]), end(mp[mx]), l);
        auto itr = lower_bound(begin(mp[mx]), end(mp[mx]), r);
        V<int> pos(itl, itr);
        pos.insert(begin(pos), l - 1);
        pos.push_back(r);
        int res = 0;
        for (int i = 0; i < ssize(pos) - 1; i++) {
            res = max(res, self(self, pos[i] + 1, pos[i + 1]));
        }
        res++;
        return res;
    };
    cout << solve(solve, 0, n) << '\n';
    return 0;
}
