// created: 07-27-2025 Sun 02:03 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct SparseTable {
    int n;
    V<V<int>> table;
    SparseTable(V<int> a) {
        n = ssize(a);
        table.assign(bit_width((unsigned)n), V<int>(n));
        table[0] = a;
        for (int i = 1; i < ssize(table); i++)
            for (int j = 0; j <= n - (1 << i); j++)
                table[i][j] = min(table[i-1][j], table[i-1][j+(1<<i-1)]);
    }
    // half open [l, r)
    int qry(int l, int r) {
        int level = bit_width((unsigned)(r - l)) - 1;
        return min(table[level][l], table[level][r-(1<<level)]);
    }
};

V<int> suffix_array(string s) {
    // construct the suffix array of s - the suffices in sorted order
    s.push_back('$');
    int n = ssize(s);
    V<int> rnk(n);
    for (int i = 0; i < n; i++)
        rnk[i] = (int)s[i];
    V<int> stuff(n);
    iota(begin(stuff), end(stuff), 0);
    for (int i = 1; i < n; i <<= 1) {
        V<array<int, 2>> pairs(n);
        for (int j = 0; j < n; j++) {
            pairs[j] = {rnk[j], rnk[(j + i) % n]};
        }
        sort(begin(stuff), end(stuff), [&pairs](int i, int j) {
            return pairs[i] < pairs[j];
        });
        array<int, 2> lst = {-1, -1};
        int cur = 0;
        for (int j : stuff) {
            if (pairs[j] != lst) {
                lst = pairs[j];
                cur++;
            }
            rnk[j] = cur;
        }
    }
    stuff.erase(begin(stuff));
    return stuff;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = ssize(s);
    V<int> sa = suffix_array(s);
    SparseTable sa_table(sa);
    int q; cin >> q;
    while (q--) {
        string t; cin >> t;
        int m = ssize(t);
        // lower_bound
        int l = 0, r = n;
        while (l < r) {
            int mid = midpoint(l, r);
            if (s.substr(sa[mid], m) >= t)
                r = mid;
            else
                l = mid + 1;
        }
        int lb = l;
        // upper_bound
        l = 0, r = n;
        while (l < r) {
            int mid = midpoint(l, r);
            if (s.substr(sa[mid], m) > t)
                r = mid;
            else
                l = mid + 1;
        }
        int ub = l;
        cout << (lb == ub ? -1 : sa_table.qry(lb, ub) + 1) << '\n';
    }
    return 0;
}
