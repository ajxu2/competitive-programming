template<typename M> class LazySeg {
private:
    using T = M::T;
    using U = M::U;
    int n;
    V<T> tree;
    V<U> lazy;
    void pull(int i) {
        tree[i] = M::val_cmb(tree[2 * i], tree[2 * i + 1]);
    }
    void push(int i) {
        lazy[2 * i] = M::lazy_cmb(lazy[2 * i], lazy[i]);
        tree[2 * i] = M::apply_lazy(tree[2 * i], lazy[i]);
        lazy[2 * i + 1] = M::lazy_cmb(lazy[2 * i + 1], lazy[i]);
        tree[2 * i + 1] = M::apply_lazy(tree[2 * i + 1], lazy[i]);
        lazy[i] = M::lazy_id;
    }
    void upd(int i, int tl, int tr, int l, int r, U v) {
        if (r <= tl || tr <= l)
            return;
        if (l <= tl && tr <= r) {
            lazy[i] = M::lazy_cmb(lazy[i], v);
            tree[i] = M::apply_lazy(tree[i], v);
        } else {
            push(i);
            int tm = midpoint(tl, tr);
            upd(2 * i, tl, tm, l, r, v);
            upd(2 * i + 1, tm, tr, l, r, v);
            pull(i);
        }
    }
    T qry(int i, int tl, int tr, int l, int r) {
        if (r <= tl || tr <= l)
            return M::val_id;
        if (l <= tl && tr <= r)
            return tree[i];
        push(i);
        int tm = midpoint(tl, tr);
        return M::val_cmb(qry(2 * i, tl, tm, l, r), qry(2 * i + 1, tm, tr, l, r));
    }
public:
    LazySeg(int _n) {
        n = 1;
        while (n < _n)
            n *= 2;
        tree.assign(2 * n, M::val_id);
        lazy.assign(2 * n, M::lazy_id);
    }
    LazySeg(const V<T>& a) {
        int _n = ssize(a);
        n = 1;
        while (n < _n)
            n *= 2;
        tree.assign(2 * n, M::val_id);
        for (int i = 0; i < _n; i++)
            tree[i + n] = a[i];
        for (int i = n - 1; i >= 1; i--)
            pull(i);
        lazy.assign(2 * n, M::lazy_id);
    }
    void range_update(int l, int r, U v) {
        upd(1, 0, n, l, r, v);
    }
    T range_query(int l, int r) {
        return qry(1, 0, n, l, r);
    }
};

struct MaxAddPolicy {
    using T = ll; // value type
    using U = ll; // lazy type
    constexpr static T val_id = 0;
    constexpr static U lazy_id = 0;
    static T val_cmb(T a, T b) {
        return max(a, b);
    }
    static U lazy_cmb(U a, U b) { // later update second
        return a + b;
    }
    static T apply_lazy(T a, U b) {
        return a + b;
    }
};
