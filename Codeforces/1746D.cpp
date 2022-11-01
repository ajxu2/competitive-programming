// created: 10-31-2022 Mon 07:02 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> adj;
vector<int> s;
vector<map<int, ll>> cache;

ll f(int node, int cnt) {
    // score for subtree node and k = cnt
    int ch = adj[node].size();
    if (ch == 0) return (ll)cnt*s[node];
    if (cache[node].count(cnt)) return cache[node][cnt];
    vector<ll> fl, ce;
    for (int i : adj[node]) {
        fl.push_back(f(i, cnt/ch));
        ce.push_back(f(i, (cnt+ch-1)/ch));
    }
    // choose cnt%ch to turn from fl to ce
    ll res = (ll)cnt*s[node];
    for (ll i : fl) res += i;
    vector<ll> diff;
    for (int i = 0; i < ch; i++) diff.push_back(ce[i] - fl[i]);
    sort(diff.begin(), diff.end(), greater<int>());
    for (int i = 0; i < cnt%ch; i++) res += diff[i];
    cache[node][cnt] = res;
    return res;
}

void solve() {
    int n, k; cin >> n >> k;
    adj = vector<vector<int>>(n+1, vector<int>());
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        adj[x].push_back(i);
    }
    s = vector<int>(n+1);
    for (int i = 1; i <= n; i++) cin >> s[i];
    cache = vector<map<int, ll>>(n+1);
    cout << f(1, k) << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
