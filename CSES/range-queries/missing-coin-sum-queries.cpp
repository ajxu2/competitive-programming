// created: 10-16-2025 Thu 05:43 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'007;
const int LOGMX = 30;

struct SparseTable {
    int n;
    V<V<int>> table;
    SparseTable(const V<int>& a) {
        n = ssize(a);
        if (n == 0)
            return;
        int logn = bit_width((unsigned)n);
        table.resize(logn);
        table[0] = a;
        for (int i = 1; i < logn; i++) {
            table[i].resize(n);
            for (int j = 0; j + (1 << i) <= n; j++) {
                table[i][j] = min(table[i-1][j], table[i-1][j+(1<<(i-1))]);
            }
        }
    }
    SparseTable() {}
    int qry(int l, int r) { // half-open [l, r)
        if (l == r)
            return INF;
        int lg = bit_width((unsigned)(r - l)) - 1;
        return min(table[lg][l], table[lg][r-(1<<lg)]);
    }
};

struct FastRMQ {
    static const int B = 48;
    int n;
    SparseTable table;
    V<uint64_t> masks; // minqueue for previous 64 elements
    V<int> a;
    FastRMQ(const V<int>& _a) {
        a = _a;
        n = ssize(a);
        masks.resize(n);
        uint64_t queue_mask = 0;
        for (int i = 0; i < n; i++) {
            queue_mask <<= 1;
            while (queue_mask > 0) {
                int nxt = countr_zero(queue_mask);
                if (a[i] <= a[i - nxt])
                    queue_mask &= ~(1ULL << nxt);
                else
                    break;
            }
            queue_mask |= 1;
            masks[i] = queue_mask;
        }
        V<int> blocks((n - 1) / B + 1, INF);
        for (int i = 0; i < n; i++) {
            int idx = i / B;
            blocks[idx] = min(blocks[idx], a[i]);
        }
        table = SparseTable(blocks);
    }
    FastRMQ() {}
    int qry_small(int l, int r) {
        // query the range [l, r) if 0 < r - l <= B
        int len = r - l;
        uint64_t mask = masks[r - 1] & ((1ULL << len) - 1);
        int msb_idx = 63 - countl_zero(mask);
        return a[r - 1 - msb_idx];
    }
    int qry(int l, int r) {
        // query the range [l, r)
        if (l == r)
            return INF;
        int len = r - l;
        if (len <= B)
            return qry_small(l, r);
        int block_left = l / B, block_right = r / B;
        int res = table.qry(block_left + 1, block_right);
        res = min(res, qry_small(l, l + B));
        res = min(res, qry_small(r - B, r));
        return res;
    }
};

struct PrefixSum {
    int n;
    V<ll> p;
    PrefixSum(const V<int>& a) {
        n = ssize(a);
        p.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            p[i + 1] = p[i] + a[i];
        }
    }
    PrefixSum() {}
    ll qry(int l, int r) { // half-open [l, r)
        return p[r] - p[l];
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // key idea: the coin that causes the missing coin sum must be
    // the first in [1, 2), or the first in [2, 4), or [4, 8), ...
    // this is because if y causes a missing coin sum, let x be the coin
    // directly before it: then x <= (sum before x) + 1 and so
    // y > (sum before y) + 1 >= 2 * x
    int n, q; cin >> n >> q;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    array<FastRMQ, LOGMX + 1> tables; // stuff at least 1 << i
    array<PrefixSum, LOGMX + 1> psums; // stuff less than 1 << i
    for (int i = 0; i <= LOGMX; i++) {
        V<int> b(n, INF), c(n, 0);
        for (int j = 0; j < n; j++) {
            if (a[j] >= 1 << i)
                b[j] = a[j];
            else
                c[j] = a[j];
        }
        tables[i] = FastRMQ(b);
        psums[i] = PrefixSum(c);
    }
    while (q--) {
        int l, r; cin >> l >> r; l--;
        for (int i = 0; i <= LOGMX; i++) {
            ll sum = psums[i].qry(l, r);
            int elt = tables[i].qry(l, r);
            if (elt == INF || elt > sum + 1) {
                cout << sum + 1 << '\n';
                break;
            }
        }
    }
    return 0;
}
