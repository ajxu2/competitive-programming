// created: 12-20-2024 Fri 10:17 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int qry(int l, int r) {
    cout << "? " << l + 1 << ' ' << r + 1 << endl;
    int res; cin >> res;
    if (res == -1) exit(0);
    return res;
}

void solve() {
    int n; cin >> n;
    array<int, 4> stuff;
    int cnt0 = 0;
    for (int i = 0; i < 3; i++) {
        stuff[i] = qry(n / 4 * i, n / 4 * (i + 1) - 1);
        if (stuff[i] == 0) cnt0++;
    }
    if (cnt0 % 2 == 1) stuff[3] = 1;
    else {
        stuff[3] = 0; cnt0++;
    }
    // k is the first length where it starts telling lies
    if (cnt0 == 3) {
        // it was truth at n/4
        int lo = n / 4 + 1, hi = n - 1;
        int idx = 0;
        for (int i = 0; i < 4; i++) if (stuff[i] == 1) idx = i;
        idx *= n / 4;
        while (lo < hi) {
            int mid = midpoint(lo, hi);
            // find suitable query range
            int l = idx, r = idx + mid - 1;
            if (r >= n) {
                int off = r - (n - 1);
                l -= off; r -= off;
            }
            if (qry(l, r) == 1) lo = mid + 1;
            else hi = mid;
        }
        cout << "! " << lo << endl;
    } else {
        // it was lie at n/4
        int lo = 2, hi = n / 4;
        int idx = 0;
        for (int i = 0; i < 4; i++) if (stuff[i] == 1) idx = i;
        idx *= n / 4;
        while (lo < hi) {
            int mid = midpoint(lo, hi);
            if (qry(idx, idx + mid - 1) == 0) lo = mid + 1;
            else hi = mid;
        }
        cout << "! " << lo << endl;
    }
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
