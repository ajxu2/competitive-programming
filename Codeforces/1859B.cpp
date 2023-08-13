// created: 08-12-2023 Sat 09:55 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

void solve() {
    int n; cin >> n;
    V<int> sec(n);
    int mn = 2e9;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        V<int> a(m);
        for (int& i : a) cin >> i;
        sort(a.begin(), a.end());
        sec[i] = a[1];
        mn = min(mn, a[0]);
    }
    sort(sec.begin(), sec.end());
    cout << mn + accumulate(sec.begin()+1, sec.end(), 0LL) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}

