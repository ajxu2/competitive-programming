// created: 04-04-2026 Sat 08:47 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s, t; cin >> s >> t;
    int n = ssize(s), m = ssize(t);
    array<V<int>, 26> pos;
    for (int i = 0; i < n; i++)
        pos[s[i] - 'a'].push_back(i);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = i - 1;
        for (int j = 0; j < m; j++) {
            int c = t[j] - 'a';
            auto it = lower_bound(begin(pos[c]), end(pos[c]), cur + 1);
            if (it == end(pos[c]))
                cur = n;
            else
                cur = *it;
        }
        ans += cur - i;
    }
    cout << ans << '\n';
    return 0;
}
