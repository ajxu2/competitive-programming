// created: 04-04-2026 Sat 08:01 AM

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
    void add(int i, int v) {
        for (; i < n; i |= i + 1)
            tree[i] += v;
    }
    int qry(int i) {
        int res = 0;
        for (; i >= 0; i &= i + 1, i--)
            res += tree[i];
        return res;
    }
    int qry(int i, int j) { return qry(j) - qry(i - 1); }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; ll k; cin >> n >> k;
    V<int> p(n);
    for (int& i : p)
        cin >> i, i--;
    Fenwick f1(n), f2(n);
    int ptr1 = 0, ptr2 = 0;
    ll inv1 = 0, inv2 = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        while (ptr1 < n && inv1 < k) {
            inv1 += f1.qry(p[ptr1], n - 1);
            f1.add(p[ptr1], 1);
            ptr1++;
        }
        while (ptr2 < n && inv2 <= k) {
            inv2 += f2.qry(p[ptr2], n - 1);
            f2.add(p[ptr2], 1);
            ptr2++;
        }
        if (ptr1 <= i)
            ptr1 = i + 1;
        ans += ptr2 - ptr1;
        if (inv2 == k)
            ans++;
        inv1 -= f1.qry(p[i] - 1);
        f1.add(p[i], -1);
        inv2 -= f2.qry(p[i] - 1);
        f2.add(p[i], -1);
    }
    cout << ans << '\n';
    return 0;
}
