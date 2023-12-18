// created: 12-18-2023 Mon 08:45 AM

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
    V<V<int>> cnt(30, V<int>(2, 0));
    for (int& i : a) {
        int d = (int)s - i;
        if (d == 0) continue;
        if (!m.contains(d)) {
            cout << "No\n";
            return;
        }
        array<int, 2> tmp = m[d];
        if (tmp[1] - tmp[0] == 1) cnt[tmp[0]][0]++;
        else if (tmp[1] - tmp[0] == -1) cnt[tmp[1]][1]++;
        whar[tmp[0]][0]++; whar[tmp[1]][1]++;
    }
    V<int> d(31);
    for (int i = 0; i < 30; i++) d[i] = whar[i][0] - whar[i][1];
    for (int i = 0; i < 30; i++) {
        if (d[i] % 2 == 1) {
            cout << "No\n";
            return;
        }
        if (d[i] > 0 && cnt[i][0] < d[i]/2) {
            cout << "No\n";
            return;
        } else if (d[i] < 0 && cnt[i][1] < -d[i]/2) {
            cout << "No\n";
            return;
        }
        d[i+1] += d[i] / 2;
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
