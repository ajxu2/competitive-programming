// created: 01-04-2025 Sat 10:41 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = (ll)1e18;

void solve() {
    // ignore wrapping around operation at first and do stuff
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    auto whar = [&](int x) -> ll {
        V<ll> b(n);
        for (int i = 0; i < n; i++) b[i] = a[i];
        for (int i = n-2; i >= 0; i--) {
            b[i] -= 2 * (x - b[i+1]);
            if (b[i] > INF) b[i] = INF;
            if (b[i] < -INF) b[i] = -INF;
        }
        return b[0];
    };
    int l = 0, r = (int)2e9;
    while (l < r) {
        int mid = midpoint(l, r);
        if (whar(mid) <= mid) r = mid;
        else l = mid + 1;
    }
    if (whar(l) != l) {
        cout << "-1\n";
        return;
    }
    // now we know all l is attainable if we allow negative ops
    V<int> ops_used(1, 0);
    for (int i = n-2; i >= 0; i--) {
        int o = l - a[i+1];
        ops_used.push_back(o);
        a[i] -= 2 * o;
    }
    int mn = *min_element(begin(ops_used), end(ops_used));
    if (l + mn < 0) {
        cout << "-1\n";
        return;
    }
    for (int& i : ops_used) i -= mn;
    cout << accumulate(begin(ops_used), end(ops_used), 0LL) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
