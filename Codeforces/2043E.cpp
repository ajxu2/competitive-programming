// created: 03-06-2025 Thu 03:16 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

template<class T> ostream& operator<<(ostream& s, const V<T>& v) {
    s << "[";
    for (int i = 0; i < ssize(v); i++) {
        s << v[i];
        if (i != ssize(v) - 1) s << ", ";
    }
    s << "]";
    return s;
}

int f(int x, int bit) { return (x >> bit) & 1; }

void solve() {
    int n, m; cin >> n >> m;
    V<V<int>> a(n, V<int>(m)), b(n, V<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    // we go bit by bit: replace any row with 0 or col with 1
    // start from the target, and remove all 0 rows and all 1 cols
    for (int bit = 0; bit < 31; bit++) {
        V<bool> row_del(n, false), col_del(m, false);
        V<array<int, 2>> row_cnt, col_cnt;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) cnt += f(b[i][j], bit) ^ 1;
            row_cnt.push_back({cnt, i});
        }
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) cnt += f(b[i][j], bit);
            col_cnt.push_back({cnt, j});
        }
        sort(begin(row_cnt), end(row_cnt), greater<array<int, 2>>());
        sort(begin(col_cnt), end(col_cnt), greater<array<int, 2>>());
        int nn = n, mm = m;
        for (;;) {
            if (nn > 0 && row_cnt[n-nn][0] == mm) {
                row_del[row_cnt[n-nn][1]] = true;
                nn--;
            } else if (mm > 0 && col_cnt[m-mm][0] == nn) {
                col_del[col_cnt[m-mm][1]] = true;
                mm--;
            } else break;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!row_del[i] && !col_del[j] && f(a[i][j], bit) != f(b[i][j], bit)) {
                    cout << "No\n";
                    return;
                }
            }
        }
    }
    cout << "Yes\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
