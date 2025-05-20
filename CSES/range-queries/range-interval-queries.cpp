// created: 05-19-2025 Mon 02:21 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int cnt(const V<int>& a, int l, int r) {
    // count how many integers in a satisfy l <= x_i <= r
    return upper_bound(begin(a), end(a), r) - lower_bound(begin(a), end(a), l);
}

struct MergesortTree {
    int n;
    V<V<int>> tree;
    MergesortTree(V<int> a) {
        int _n = ssize(a);
        n = 1;
        while (n < _n)
            n *= 2;
        tree.resize(2*n);
        for (int i = 0; i < _n; i++)
            tree[i+n].push_back(a[i]);
        for (int i = n-1; i >= 1; i--) {
            tree[i].resize(ssize(tree[2*i]) + ssize(tree[2*i+1]));
            merge(begin(tree[2*i]), end(tree[2*i]),
                  begin(tree[2*i+1]), end(tree[2*i+1]),
                  begin(tree[i]));
        }
    }
    int qry(int a, int b, int c, int d) {
        // count how many integers satisfy a <= i <= b and c <= x_i <= d
        int res = 0;
        a += n; b += n;
        while (a <= b) {
            if (a % 2 == 1)
                res += cnt(tree[a++], c, d);
            if (b % 2 == 0)
                res += cnt(tree[b--], c, d);
            a /= 2; b /= 2;
        }
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // mergesort tree yay!
    int n, q; cin >> n >> q;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    MergesortTree mt(a);
    while (q--) {
        int a, b, c, d; cin >> a >> b >> c >> d; a--, b--;
        cout << mt.qry(a, b, c, d) << '\n';
    }
    return 0;
}
