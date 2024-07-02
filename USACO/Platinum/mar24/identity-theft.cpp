// created: 07-02-2024 Tue 05:15 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

struct Node {
    Node* par;
    array<Node*, 2> ch = {nullptr, nullptr};
    Node(Node* par) : par(par) {}
    unordered_set<int> ids; // :trust:
    pair<int, Node*> cost; // cost to "solve" a bitstring here
    void pull() {
        if (ch[0] == nullptr && ch[1] == nullptr) cost = {2, this};
        else if ((ch[0] == nullptr) ^ (ch[1] == nullptr)) cost = {1, this};
        else {
            cost = min(ch[0]->cost, ch[1]->cost);
            cost.first++;
        }
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<string> a(n);
    for (string& i : a) cin >> i;
    sort(begin(a), end(a), [](const string& s, const string& t) { return sz(s) > sz(t); });
    Node* root = new Node(nullptr);
    V<Node*> ptrs(n);
    for (int i = 0; i < n; i++) {
        string s = a[i];
        Node* cur = root;
        for (int j = 0; j < sz(s); j++) {
            int bit = s[j] - '0';
            if (cur->ch[bit] == nullptr) cur->ch[bit] = new Node(cur);
            cur = cur->ch[bit];
        }
        cur->ids.insert(i);
        ptrs[i] = cur;
        while (cur != nullptr) {
            cur->pull(); cur = cur->par;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        Node* cur = ptrs[i];
        if (cur->ch[0] == nullptr && cur->ch[1] == nullptr && sz(cur->ids) == 1) continue;
        ans += cur->cost.first;
        cur->ids.erase(i);
        cur = cur->cost.second;
        if (cur->ch[0] == nullptr && cur->ch[1] == nullptr) {
            auto it = begin(cur->ids);
            int val = *it;
            cur->ids.erase(it);
            cur->ch[0] = new Node(cur); cur->ch[1] = new Node(cur);
            cur->ch[0]->ids.insert(i); cur->ch[1]->ids.insert(val);
            ptrs[i] = cur->ch[0]; ptrs[val] = cur->ch[1];
            cur->ch[0]->pull(); cur->ch[1]->pull();
        } else if (cur->ch[0] == nullptr) {
            cur->ch[0] = new Node(cur);
            cur->ch[0]->ids.insert(i);
            ptrs[i] = cur->ch[0];
            cur->ch[0]->pull();
        } else if (cur->ch[1] == nullptr) {
            cur->ch[1] = new Node(cur);
            cur->ch[1]->ids.insert(i);
            ptrs[i] = cur->ch[1];
            cur->ch[1]->pull();
        }
        while (cur != nullptr) {
            cur->pull(); cur = cur->par;
        }
    }
    cout << ans << '\n';
    return 0;
}
