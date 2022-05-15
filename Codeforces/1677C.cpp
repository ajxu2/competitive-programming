// created: 05-13-2022 Fri 11:39 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Do I know why this works? No.
// Does it work? Yes.
// Did I only get this because of the editorial? No comment.

void solve() {
    int n; cin >> n;
    vector<int> a(n+1), tmp1(n), tmp2(n);
    for (int i = 0; i < n; i++) cin >> tmp1[i];
    for (int i = 0; i < n; i++) cin >> tmp2[i];
    for (int i = 0; i < n; i++) a[tmp1[i]] = tmp2[i];
    vector<bool> vis(n+1, false);
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int cnt = 0, x = i, orig = i;
        do {
            x = a[x];
            vis[x] = true;
            cnt++;
        } while (x != orig);
        c += cnt/2;
    }
    cout << 2LL*c*(n-c) << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
