// created: 12-10-2023 Sun 03:04 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

map<int, array<int, 2>> m;

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    ll s = accumulate(begin(a), end(a), 0LL);
    if (s % n != 0) {
        cout << "No\n";
        return;
    }
    s /= n;
    V<V<int>> whar(31, V<int>(2, 0));
    for (int& i : a) {
        int d = (int)s - i;
        if (d == 0) continue;
        if (!m.contains(d)) {
            cout << "No\n";
            return;
        }
        whar[m[d][0]][0]++; whar[m[d][1]][1]++;
    }
    for (V<int>& i : whar) {
        if (i[0] != i[1]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i <= 30; i++) {
        for (int j = 0; j <= 30; j++) {
            if (i == j) continue;
            m[(1<<i)-(1<<j)] = {i, j};
        }
    }
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
