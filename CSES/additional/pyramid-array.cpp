// created: 03-04-2026 Wed 06:12 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct Fenwick {
    int n;
    V<int> tree;
    Fenwick(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void add(int i, int x) {
        for (int j = i; j < n; j |= j + 1)
            tree[j] += x;
    }
    int qry(int i) {
        int res = 0;
        for (int j = i; j >= 0; j &= j + 1, j--)
            res += tree[j];
        return res;
    }
    int qry(int i, int j) {
        return qry(j) - qry(i - 1);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    map<int, V<int>> pos;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pos[x].push_back(i);
    }
    Fenwick fenwick(n);
    for (int i = 0; i < n; i++)
        fenwick.add(i, 1);
    ll ans = 0;
    for (auto [x, v] : pos) {
        for (int i : v)
            fenwick.add(i, -1);
        for (int i : v)
            ans += min(fenwick.qry(i - 1), fenwick.qry(i + 1, n - 1));
    }
    cout << ans << '\n';
    return 0;
}
