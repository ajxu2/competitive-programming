// created: 10-09-2023 Mon 10:10 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    string s; cin >> s;
    int n = sz(s);
    V<ll> search(n); search[0] = n;
    for (int i = 1; i < n; i++) search[i] = search[i-1] + (n-i);
    ll x; cin >> x;
    auto it = lower_bound(begin(search), end(search), x);
    int pos1 = distance(begin(search), it), pos2 = (pos1 == 0 ? x-1 : x-search[pos1-1]-1);
    priority_queue<int, V<int>, greater<int>> down;
    for (int i = n-2; i >= 0; i--) if (s[i] > s[i+1]) down.push(i);
    V<int> prv(n), nxt(n);
    iota(begin(prv), end(prv), -1);
    iota(begin(nxt), end(nxt), 1);
    int af = 0;
    for (int i = 0; i < pos1; i++) {
        if (down.empty()) {
            af = pos1 - i;
            break;
        }
        int proc = down.top(); down.pop();
        s[proc] = ' ';
        if (prv[proc] == -1) {
            prv[nxt[proc]] = prv[proc];
            continue;
        }
        if (nxt[proc] == n) {
            nxt[prv[proc]] = nxt[proc];
            continue;
        }
        int bruh1 = prv[proc], bruh2 = nxt[proc];
        prv[bruh2] = bruh1; nxt[bruh1] = bruh2;
        if (s[bruh1] > s[bruh2]) down.push(bruh1);
    }
    s.erase(remove(begin(s), end(s), ' '), end(s));
    s.erase(end(s) - af, end(s));
    cout << s[pos2];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
