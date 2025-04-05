// created: 03-13-2025 Thu 08:54 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

ll cdiv(ll a, ll b) { return (a + b - 1) / b; }
ll sq(ll a) { return a * a; }
ll isqrt(ll a) {
    ll l = 0, r = a;
    while (l < r) {
        ll mid = midpoint(l, r + 1);
        if (sq(mid) <= a) l = mid;
        else r = mid - 1;
    }
    return l;
}

void solve() {
    int x, y, z, k; cin >> x >> y >> z >> k;
    // key idea - any optimal sequence of operations consists of "blocks"
    // of k * type 1 + type 2, then some more type 1, then type 2
    // we can brute force over the number of blocks since there are at most
    // O(sqrt(z/k)) of them; then for the remaining, we can brute force in
    // O(min(sqrt(z),k)), total runtime can be proven to be O(z^0.75)
    int cur_damage = 0, blocks = 0;
    ll ans = numeric_limits<ll>::max();
    while (cur_damage < z) {
        int remaining = z - cur_damage;
        auto cost = [&](ll a) {
            if (k * blocks + a == 0) return numeric_limits<ll>::max();
            return x * a + y * cdiv(remaining, (ll)k * blocks + a);
        };
        ll cur_cost = numeric_limits<ll>::max();
        if (z < sq(k)) {
            // brute force over O(sqrt(z)) possibilities
            for (int i = 0; i <= k && sq(k * blocks + i) <= remaining; i++)
                cur_cost = min(cur_cost, cost(i));
            for (ll i = isqrt(remaining) + 1; i >= 1; i--) {
                ll best = cdiv(remaining, i) - (ll)k * blocks;
                best = clamp(best, 0LL, (ll)k);
                cur_cost = min(cur_cost, cost(best));
            }
        } else {
            // brute force over all k+1 possibilities
            for (int i = 0; i <= k; i++) cur_cost = min(cur_cost, cost(i));
        }
        ans = min(ans, ((ll)k * x + y) * blocks + cur_cost);
        blocks++;
        cur_damage += k * blocks;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
