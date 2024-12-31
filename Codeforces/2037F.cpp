// created: 12-30-2024 Mon 08:03 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int BIG = 1'000'000'007;
int cdiv(int x, int y) { return (x + y - 1) / y; }

void solve() {
    int n, m, k; cin >> n >> m >> k;
    V<int> h(n), x(n);
    for (int& i : h) cin >> i;
    for (int& i : x) cin >> i;
    auto check = [&](int attacks) -> bool {
        // can we defeat k enemies with the given number of attacks
        map<int, int> intervals;
        for (int i = 0; i < n; i++) {
            int damage = cdiv(h[i], attacks);
            if (damage <= m) {
                int l = x[i] - (m - damage), r = x[i] + (m - damage);
                intervals[l]++; intervals[r+1]--;
            }
        }
        int elevation = 0, max_killed = 0;
        for (pair<int, int> i : intervals) {
            elevation += i.second;
            max_killed = max(max_killed, elevation);
        }
        return max_killed >= k;
    };
    int l = 1, r = BIG;
    while (l < r) {
        int mid = midpoint(l, r);
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << (l == BIG ? -1 : l) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
