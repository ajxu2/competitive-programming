// created: 04-27-2025 Sun 08:41 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct TrieNode {
    int cnt_x = 0, cnt_y = 0;
    array<TrieNode*, 26> ch;
    TrieNode() {
        ch.fill(nullptr);
    }
    int sum_y() {
        int res = cnt_y;
        for (TrieNode *i : ch) {
            if (i != nullptr)
                res += i->sum_y();
        }
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q; cin >> q;
    int ans = 0;
    TrieNode *trie = new TrieNode();
    while (q--) {
        int t; cin >> t;
        string s; cin >> s;
        if (t == 1) {
            TrieNode *cur = trie;
            for (char c : s) {
                if (cur->cnt_x != 0)
                    break;
                if (cur->ch[c - 'a'] == nullptr)
                    cur->ch[c - 'a'] = new TrieNode();
                cur = cur->ch[c - 'a'];
            }
            cur->cnt_x++;
            ans -= cur->sum_y();
            for (int i = 0; i < 26; i++)
                cur->ch[i] = nullptr;
            cur->cnt_y = 0;
        } else {
            TrieNode *cur = trie;
            bool add_one = true;
            for (char c : s) {
                if (cur->cnt_x != 0) {
                    add_one = false;
                    break;
                }
                if (cur->ch[c - 'a'] == nullptr)
                    cur->ch[c - 'a'] = new TrieNode();
                cur = cur->ch[c - 'a'];
            }
            if (cur->cnt_x != 0)
                add_one = false;
            if (add_one) {
                ans++;
                cur->cnt_y++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
