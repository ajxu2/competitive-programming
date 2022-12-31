// created: 12-31-2022 Sat 12:12 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, m; cin >> n >> m;
    V<V<int>> a(n, V<int>(m));
    V<int> sum(n, 0);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            sum[i] += a[i][j];
            tot += a[i][j];
        }
    }
    if (tot % n != 0) {
        cout << "-1\n";
        return;
    }
    V<array<int, 3>> ans;
    for (int j = 0; j < m; j++) {
        // fix this column
        V<int> give, receive;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == 1 && sum[i] > tot/n) give.push_back(i);
            if (a[i][j] == 0 && sum[i] < tot/n) receive.push_back(i);
        }
        for (int i = 0; i < min(give.size(), receive.size()); i++) {
            ans.push_back({give[i]+1, receive[i]+1, j+1});
            sum[give[i]]--; sum[receive[i]]++;
        }
    }
    cout << ans.size() << "\n";
    for (array<int, 3> i : ans) cout << i[0] << " " << i[1] << " " << i[2] << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
