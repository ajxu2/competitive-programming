#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<ll> a(n);
    for (ll& i : a) cin >> i;
    V<set<ll>> poss(n); // for each index, a possible value of x that would result in >1 square
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            ll diff = a[j] - a[i]; // diff. of squares
            for (ll minus = 1; minus * minus <= diff; minus++) {
                if (diff % minus != 0) continue;
                ll plus = diff / minus;
                if (minus % 2 != plus % 2) continue;
                ll sq1 = (plus - minus) / 2, x = sq1 * sq1 - a[i];
                if (x < 0 || x > 1e18) continue;
                poss[i].insert(x); poss[j].insert(x);
            }
        }
    }
    map<ll, int> m;
    for (int i = 0; i < n; i++) for (ll j : poss[i]) m[j]++;
    int ans = 1;
    for (pair<ll, int> i : m) ans = max(ans, i.second);
    cout << ans << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
}
