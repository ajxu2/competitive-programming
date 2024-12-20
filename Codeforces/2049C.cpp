// created: 12-20-2024 Fri 08:54 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, x, y; cin >> n >> x >> y; x--, y--;
    V<int> ans(n);
    if (n % 2 == 1) {
        // start from x, fill with 2, fill others with alternating 0/1
        ans[x] = 2;
        for (int i = 1; i < n; i++) {
            ans[(x+i)%n] = i % 2;
        }
    } else {
        if ((y - x) % 2 == 1) {
            // alternating 0/1
            for (int i = 0; i < n; i++) ans[i] = i % 2;
        } else {
            // 1s, 2s flanking, alternating 0/1
            ans[x] = 1;
            ans[(x+1)%n] = 2;
            ans[(x+n-1)%n] = 2;
            for (int i = 2; i < n-1; i++) ans[(x+i)%n] = i % 2;
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n-1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
