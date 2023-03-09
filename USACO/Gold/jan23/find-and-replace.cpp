// created: 02-26-2023 Sun 04:49 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = 2'000'000'000'000'000'000;

struct Tree {
    V<Tree*> children;
    int c; // character corresponding to root
    ll sz = 0; // number of leaves (not subtree size)
    bool leaf;
    Tree(int _c, bool _leaf, V<Tree*> _children) {
        c = _c; leaf = _leaf; children = _children;
        if (leaf) sz = 1;
        else for (Tree* i : children) sz = min(sz + i->sz, INF); // cap size
    }
    void pr(ll l, ll r) {
        // print [l, r) of this string
        if (l == r) return;
        if (leaf) {
            cout << (char)(c + 'a');
            return;
        }
        ll sofar = 0; // total size already taken
        for (Tree* i : children) {
            i->pr(clamp(l - sofar, 0LL, i->sz), clamp(r - sofar, 0LL, i->sz));
            sofar = min(sofar + i->sz, INF);
        }
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll l, r; int n;
    cin >> l >> r >> n;
    V<pair<int, V<int>>> ops;
    for (int i = 0; i < n; i++) {
        char c; string s; cin >> c >> s;
        V<int> s2;
        for (char j : s) s2.push_back(j - 'a');
        ops.push_back({c - 'a', s2});
    }
    V<Tree*> cur(26); // cur[i] = pointers to subtrees of char i
    for (int i = 0; i < 26; i++) cur[i] = new Tree(i, true, V<Tree*>());
    for (int i = n-1; i >= 0; i--) {
        int upd = ops[i].first;
        // update cur[upd]
        if (ops[i].second.size() == 1) {
            // no need to make a new tree
            cur[upd] = cur[ops[i].second[0]];
            continue;
        }
        V<Tree*> children;
        for (int j : ops[i].second) children.push_back(cur[j]);
        cur[upd] = new Tree(upd, false, children);
    }
    cur[0]->pr(l-1, r); cout << "\n";
    return 0;
}
