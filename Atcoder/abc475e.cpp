// created: 09-12-2026 Sat 08:51 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct TrieNode {
    TrieNode *l, *r;
    int cnt;
    void upd() {
        cnt = (l == nullptr ? 0 : l->cnt) + (r == nullptr ? 0 : r->cnt);
    }
    void add(const string& s, int i) {
        if (i == ssize(s))
            return;
        if (s[i] == '0') {
            if (l == nullptr)
                l = new TrieNode();
        }
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    string t; cin >> t;
    V<string> a(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        string b(k, 0);
        for (int j = 0; j < k; j++) {
            if (s[j] == t[j]) // answer correct
                b[j] = '1';
            else // answer wrong
                b[j] = '0';
        }
        a[i] = b;
    }
    // insert all strings into trie
    TrieNode *trie = new TrieNode();
    auto incr_cnt = [&](const string& s, int delta) -> void {
        TrieNode *cur = trie;
        for (char c : s) {
            cur->cnt += delta;
            if (c == '0') {
                if (cur->l == nullptr)
                    cur->l = new TrieNode();
                cur = cur->l;
            } else {
                if (cur->r == nullptr)
                    cur->r = new TrieNode();
                cur = cur->r;
            }
        }
        cur->cnt += delta;
    };
    auto get_cnt = [&](TrieNode *t) -> int {
        return t == nullptr ? 0 : t->cnt;
    };
    for (const string& i : a)
        incr_cnt(i, 1);
    int q; cin >> q;
    while (q--) {
        int i, j; cin >> i >> j; i--, j--;
        incr_cnt(a[i], -1);
        a[i][j] = (a[i][j] == '0' ? '1' : '0');
        incr_cnt(a[i], 1);
        TrieNode *cur = trie;
        bool passed = false;
        int qualifiers = 0;
        for (char c : a[i]) {
            if (c == '0') {
                if (qualifiers + get_cnt(cur->r) > m) {
                    passed = false;
                    break;
                }
                qualifiers += get_cnt(cur->r);
                cur = cur->l;
            } else if (c == '1') {
                if (qualifiers + get_cnt(cur->r) <= m) {
                    passed = true;
                    break;
                }
                cur = cur->r;
            }
        }
        cout << (passed ? "Yes" : "No") << '\n';
    }
    return 0;
}
