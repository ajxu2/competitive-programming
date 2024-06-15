// created: 06-15-2024 Sat 11:16 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    Node *lch = nullptr, *rch = nullptr;
    unsigned pri;
    char v;
    int sz = 1;
    bool flip = false;
    Node(char _v) : pri(rng()), v(_v) {}
};

int get_sz(Node* a) { return a == nullptr ? 0 : a->sz; }
void upd_sz(Node* a) { a->sz = get_sz(a->lch) + get_sz(a->rch) + 1; }
void toggle(Node* a) {
    if (a == nullptr) return;
    a->flip = !a->flip;
}
void push(Node* a) {
    if (a->flip) {
        swap(a->lch, a->rch);
        toggle(a->lch); toggle(a->rch);
        a->flip = false;
    }
}

array<Node*, 2> split(Node* a, int num) {
    // splits a into treaps of size num and a->sz - num
    if (a == nullptr) return {nullptr, nullptr};
    push(a);
    if (num <= get_sz(a->lch)) {
        array<Node*, 2> tmp = split(a->lch, num);
        a->lch = tmp[1]; upd_sz(a);
        return {tmp[0], a};
    } else {
        array<Node*, 2> tmp = split(a->rch, num - get_sz(a->lch) - 1);
        a->rch = tmp[0]; upd_sz(a);
        return {a, tmp[1]};
    }
}

Node* merge(Node* a, Node* b) {
    // merges treaps a and b (inverse of split)
    if (a == nullptr) return b;
    if (b == nullptr) return a;
    push(a); push(b);
    if (a->pri > b->pri) {
        a->rch = merge(a->rch, b); upd_sz(a);
        return a;
    } else {
        b->lch = merge(a, b->lch); upd_sz(b);
        return b;
    }
}

ostream& operator<<(ostream& s, Node* a) {
    // print treap
    if (a == nullptr) return s;
    push(a);
    return s << a->lch << a->v << a->rch;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    Node* treap = nullptr;
    for (char i : s) treap = merge(treap, new Node(i));
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r; l--, r--;
        array<Node*, 2> tmp1 = split(treap, l);
        array<Node*, 2> tmp2 = split(tmp1[1], r - l + 1);
        // tmp1[0], tmp2[0], tmp2[1] are our three parts
        toggle(tmp2[0]);
        treap = merge(merge(tmp1[0], tmp2[0]), tmp2[1]);
    }
    cout << treap << '\n';
    return 0;
}
