// created: 08-12-2023 Sat 10:53 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

void solve() {
    int n; cin >> n;
    V<array<int, 4>> a(n+1); // l, r, a, b
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a[i][j];
        }
    }
    V<array<int, 2>> events; // idx, +- some i
    for (int i = 1; i <= n; i++) {
        events.push_back({a[i][0]-1, i});
        events.push_back({a[i][1], -i});
    }
    sort(events.begin(), events.end());
    map<int, int> ans; // answers for interval ending at i
    ans[2e9] = -1;
    multiset<int> tmp;
    for (int i = sz(events)-1; i >= 0; i--) {
        if (events[i][1] > 0) tmp.erase(tmp.find(a[events[i][1]][3]));
        else tmp.insert(a[-events[i][1]][3]);
        if (sz(tmp) == 0) {
            ans[events[i][0]] = -1;
            continue;
        }
        int jmp = *(tmp.rbegin());
        ans[events[i][0]] = jmp;
        auto it = ans.lower_bound(jmp);
        ans[events[i][0]] = max(ans[events[i][0]], it->second);
    }
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        auto it = ans.lower_bound(x);
        cout << max(it->second, x) << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
