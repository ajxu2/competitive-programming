// created: 05-31-2023 Wed 08:17 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, k; cin >> n >> k;
    V<int> l(n), r(n);
    for (int& i : l) cin >> i;
    for (int& i : r) cin >> i;
    int sum = 0, cur = 0, single = 0;
    while (cur < n && sum + r[cur] - l[cur] + 1 < k) {
        sum += r[cur] - l[cur] + 1;
        if (l[cur] == r[cur]) single++;
        cur++;
    }
    if (cur == n) {
        cout << "-1\n";
        return;
    }
    int curpos = l[cur] + (k - sum) - 1, used = cur + 1;
    int ans = curpos + 2 * used;
    while (single > 0) {
        // advance cursor
        if (curpos == r[cur]) {
            if (cur == n-1) break;
            else {
                if (l[cur] == r[cur]) single++;
                cur++; curpos = l[cur]; used++;
            }
        } else curpos++;
        // use up a single
        single--; used--;
        ans = min(ans, curpos + 2 * used);
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
