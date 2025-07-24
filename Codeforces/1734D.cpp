// created: 07-23-2025 Wed 11:04 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, k; cin >> n >> k; k--;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    queue<array<ll, 2>> lq, rq; // (health diff, amount health needed)
    ll sum = 0, mn = 0;
    for (int i = k-1; i >= 0; i--) {
        sum += a[i];
        mn = min(mn, sum);
        if (sum > 0) {
            lq.push({sum, -mn});
            sum = 0;
            mn = 0;
        }
    }
    lq.push({sum, -mn});
    sum = 0, mn = 0;
    for (int i = k+1; i < n; i++) {
        sum += a[i];
        mn = min(mn, sum);
        if (sum > 0) {
            rq.push({sum, -mn});
            sum = 0;
            mn = 0;
        }
    }
    rq.push({sum, -mn});
    ll cur_health = a[k];
    while (!lq.empty() && !rq.empty()) {
        auto [ldiff, lneeded] = lq.front();
        auto [rdiff, rneeded] = rq.front();
        if (lneeded > cur_health && rneeded > cur_health) {
            cout << "NO\n";
            return;
        }
        if (lneeded < rneeded) {
            cur_health += ldiff;
            lq.pop();
        } else {
            cur_health += rdiff;
            rq.pop();
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
