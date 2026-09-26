// created: 09-26-2026 Sat 08:35 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> using min_pq = priority_queue<T, V<T>, greater<T>>;

const ll INF = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    V<int> a(n), b(n);
    for (int& i : a)
        cin >> i;
    for (int& i : b)
        cin >> i;
    // duplicate a for convenience
    for (int i = 0; i < n; i++)
        a.push_back(a[i]);
    V<ll> p(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++)
        p[i] = p[i - 1] + a[i - 1];
    // calculate distances from n to every other vtx
    V<ll> dist_from_n(n, INF);
    min_pq<pair<ll, int>> pq;
    for (int i = 0; i < n; i++)
        pq.push({b[i], i});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist_from_n[u] != INF)
            continue;
        dist_from_n[u] = d;
        int pre = (u + n - 1) % n;
        pq.push({d + a[pre], pre});
        pq.push({d + a[u], (u + 1) % n});
    }
    for (int i = 0; i < q; i++) {
        int s, t; cin >> s >> t; s--, t--;
        if (t == n) {
            cout << dist_from_n[s] << '\n';
        } else {
            // travel s -> t clockwise
            ll ans = p[t] - p[s];
            // travel s -> t counterclockwise
            ans = min(ans, p[s + n] - p[t]);
            ans = min(ans, dist_from_n[s] + dist_from_n[t]);
            cout << ans << '\n';
        }
    }
    return 0;
}
