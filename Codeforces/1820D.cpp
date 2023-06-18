// created: 06-17-2023 Sat 10:38 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

array<ll, 2> solv(const V<array<int, 2>>& a, int h) {
    int mx = 0;
    ll area = 0;
    for (array<int, 2> i : a) {
        mx = max(mx, i[h]);
        area += (ll)i[0] * i[1];
    }
    if (area % mx != 0) return {-1, -1};
    array<ll, 2> dim;
    dim[h] = mx; dim[(h+1)%2] = area/mx;
    array<ll, 2> odim = dim;
    array<map<int, multiset<int>>, 2> mp; // yay bidirectional references!
    for (array<int, 2> i : a) {
        mp[0][i[0]].insert(i[1]);
        mp[1][i[1]].insert(i[0]);
    }
    int op = h;
    for (;;) {
        if (dim[0] == 0 || dim[1] == 0) return odim;
        if (mp[op][dim[op]].empty()) return {-1, -1};
        for (int i : mp[op][dim[op]]) {
            // remove all with dimension dim[op]
            int nop = (op+1)%2;
            multiset<int>& bruh = mp[nop][i];
            bruh.erase(bruh.find(dim[op]));
            dim[nop] -= i;
        }
        mp[op].erase(dim[op]);
        op = (op+1)%2;
    }
}

void solve() {
    int n; cin >> n;
    V<array<int, 2>> a(n);
    for (array<int, 2>& i : a) cin >> i[0] >> i[1];
    set<array<ll, 2>> ans;
    ans.insert(solv(a, 0));
    ans.insert(solv(a, 1));
    ans.erase({-1, -1});
    cout << sz(ans) << "\n";
    for (array<ll, 2> i : ans) cout << i[0] << " " << i[1] << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
