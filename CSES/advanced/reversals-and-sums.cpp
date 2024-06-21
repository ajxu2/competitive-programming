// created: 06-16-2024 Sun 10:55 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
    Node *lch = nullptr, *rch = nullptr;
    unsigned pri;
    int v;
    int sz = 1;
    ll sum;
    bool flip = false;
    Node(int _v) : pri(rng()), v(_v), sum(_v) {}
};

int get_sz(Node* a) { return a == nullptr ? 0 : a->sz; }
ll get_sum(Node* a) { return a == nullptr ? 0 : a->sum; }
void upd(Node* a) {
    a->sz = get_sz(a->lch) + get_sz(a->rch) + 1;
    a->sum = get_sum(a->lch) + get_sum(a->rch) + a->v;
}
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
        a->lch = tmp[1]; upd(a);
        return {tmp[0], a};
    } else {
        array<Node*, 2> tmp = split(a->rch, num - get_sz(a->lch) - 1);
        a->rch = tmp[0]; upd(a);
        return {a, tmp[1]};
    }
}

Node* merge(Node* a, Node* b) {
    // merges treaps a and b (inverse of split)
    if (a == nullptr) return b;
    if (b == nullptr) return a;
    push(a); push(b);
    if (a->pri > b->pri) {
        a->rch = merge(a->rch, b); upd(a);
        return a;
    } else {
        b->lch = merge(a, b->lch); upd(b);
        return b;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    Node* treap = nullptr;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        treap = merge(treap, new Node(tmp));
    }
    while (q--) {
        int t, a, b; cin >> t >> a >> b; a--, b--;
        array<Node*, 2> tmp1 = split(treap, a);
        array<Node*, 2> tmp2 = split(tmp1[1], b - a + 1);
        // tmp1[0], tmp2[0], tmp2[1] are our three parts
        if (t == 1) toggle(tmp2[0]);
        else cout << get_sum(tmp2[0]) << '\n';
        treap = merge(merge(tmp1[0], tmp2[0]), tmp2[1]);
    }
    return 0;
}
