// created: 03-07-2025 Fri 04:07 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct TrieNode {
    int len;
    set<int> ids;
    TrieNode *par, *best;
    map<char, TrieNode*> ch;
    TrieNode() {}
    void upd_best() {
        TrieNode *cur_best = empty(ids) ? nullptr : this;
        for (auto [c, i] : ch) {
            if (i == nullptr) continue;
            else if (cur_best == nullptr) cur_best = i->best;
            else if (i->best->len > cur_best->len) cur_best = i->best;
        }
        best = cur_best;
    }
    bool useless() {
        return empty(ids) && empty(ch);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<TrieNode*> a(n+1, nullptr);
    TrieNode *trie = new TrieNode();
    trie->len = 0; trie->par = nullptr; trie->best = nullptr;
    deque<char> remaining; // definitely not jank
    TrieNode *cur = trie;
    while (n--) {
        string action; cin >> action;
        if (action == "add") {
            int id; cin >> id;
            string s; cin >> s;
            // add s to the trie
            TrieNode *ptr = trie;
            for (char i : s) {
                if (!ptr->ch.contains(i)) {
                    TrieNode *tmp = new TrieNode();
                    tmp->len = ptr->len + 1;
                    tmp->par = ptr;
                    ptr->ch[i] = tmp;
                }
                ptr = ptr->ch[i];
            }
            ptr->ids.insert(id);
            a[id] = ptr;
            while (ptr != nullptr) {
                ptr->upd_best();
                ptr = ptr->par;
            }
            while (!empty(remaining) && cur->ch.contains(remaining.front())) {
                cur = cur->ch[remaining.front()];
                remaining.pop_front();
            }
        } else if (action == "delete") {
            int id; cin >> id;
            TrieNode *ptr = a[id];
            ptr->ids.erase(id);
            while (ptr->par != nullptr && ptr->useless()) {
                // node is useless, delete
                TrieNode *tmp = ptr;
                ptr = ptr->par;
                char del = ' ';
                for (auto [c, i] : ptr->ch) {
                    if (i == tmp) del = c;
                }
                ptr->ch.erase(del);
                if (cur == tmp) {
                    // move up
                    cur = ptr;
                    remaining.push_front(del);
                }
                delete tmp;
            }
            while (ptr != nullptr) {
                ptr->upd_best();
                ptr = ptr->par;
            }
        } else if (action == "append") {
            string s; cin >> s;
            for (char i : s) remaining.push_back(i);
            while (!empty(remaining) && cur->ch.contains(remaining.front())) {
                cur = cur->ch[remaining.front()];
                remaining.pop_front();
            }
        } else if (action == "backspace") {
            int c; cin >> c;
            while (c > 0 && !empty(remaining)) {
                remaining.pop_back();
                c--;
            }
            while (c > 0 && cur->par != nullptr) {
                cur = cur->par;
                c--;
            }
        }
        if (empty(remaining) && cur->best != nullptr) cout << *begin(cur->best->ids) << '\n';
        else cout << "-1\n";
    }
    return 0;
}
