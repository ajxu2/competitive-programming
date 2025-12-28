// created: 12-27-2025 Sat 08:39 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    string s; cin >> s;
    int n = ssize(s);
    int ans = 0;
    if (s[0] != 's') {
        s[0] = 's';
        ans++;
    }
    if (s[n - 1] != 's') {
        s[n - 1] = 's';
        ans++;
    }
    V<int> chunks;
    int last_s = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 's') {
            if (i - last_s - 1 > 0)
                chunks.push_back(i - last_s - 1);
            last_s = i;
        }
    }
    for (int i : chunks)
        ans += i / 2;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
