// created: 05-25-2025 Sun 10:45 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'007;

struct Segtree {
    int n;
    V<int> tree;
    Segtree(int _n) {
        n = 1;
        while (n < _n)
            n *= 2;
        tree.assign(2*n, INF);
    }
    void upd(int i, int x) {
        i += n;
        tree[i] = x;
        for (i /= 2; i >= 1; i /= 2)
            tree[i] = min(tree[2*i], tree[2*i+1]);
    }
    int qry(int l, int r) {
        int res = INF;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1)
                res = min(res, tree[l++]);
            if (r % 2 == 0)
                res = min(res, tree[r--]);
        }
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    V<int> a(n);
    for (int& i : a)
         cin >> i;
    map<int, set<int>> mp; // for each number, where it occurs
    for (int i = 0; i < n; i++)
        mp[a[i]].insert(i);
    Segtree st(n); // segtree will store the idx of next occurrence
    for (auto [i, se] : mp) {
        for (auto it = begin(se); next(it) != end(se); it++)
            st.upd(*it, *next(it));
    }
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int k, u; cin >> k >> u; k--;
            // remove old connections
            set<int>& se = mp[a[k]];
            auto it = se.find(k);
            if (it != begin(se)) {
                if (next(it) == end(se))
                    st.upd(*prev(it), INF);
                else
                    st.upd(*prev(it), *next(it));
            }
            se.erase(it);
            a[k] = u;
            set<int>& se2 = mp[a[k]];
            it = se2.insert(k).first;
            if (next(it) == end(se2))
                st.upd(*it, INF);
            else
                st.upd(*it, *next(it));
            if (it != begin(se2))
                st.upd(*prev(it), *it);
        } else {
            int l, r; cin >> l >> r; l--, r--;
            cout << (st.qry(l, r) <= r ? "NO" : "YES") << '\n';
        }
    }
    return 0;
}
