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
        for (; i < n; i |= i + 1)
            tree[i] += x;
    }
    int qry(int i) {
        int res = 0;
        for (; i >= 0; i &= i + 1, i--)
            res += tree[i];
        return res;
    }
};

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    V<int> b = a;
    sort(begin(b), end(b));
    b.erase(unique(begin(b), end(b)), end(b));
    for (int& i : a)
        i = lower_bound(begin(b), end(b), i) - begin(b);
    V<V<int>> pos(n);
    for (int i = 0; i < n; i++)
        pos[a[i]].push_back(i);
    Fenwick fenwick(n);
    for (int i = 0; i < n; i++)
        fenwick.add(i, 1);
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j : pos[i]) {
            fenwick.add(j, -1);
        }
        for (int j : pos[i]) {
            int one = fenwick.qry(j);
            int two = fenwick.qry(n - 1) - fenwick.qry(j);
            ans += min(one, two);
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
