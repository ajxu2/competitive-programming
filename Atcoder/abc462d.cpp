// created: 06-13-2026 Sat 09:31 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

ll c2(int x) {
    return (ll)x * (x - 1) / 2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, d; cin >> n >> d;
    V<array<int, 2>> events;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        if (r - l >= d) {
            events.push_back({l, 1});
            events.push_back({r + 1 - d, -1});
        }
    }
    sort(begin(events), end(events));
    int available = 0;
    ll ans = 0;
    for (int i = 0; i < ssize(events) - 1; i++) {
        available += events[i][1];
        ans += (ll)(events[i + 1][0] - events[i][0]) * c2(available);
    }
    cout << ans << '\n';
    return 0;
}
