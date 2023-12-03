// created: 12-03-2023 Sun 09:27 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

using Pair = array<int, 2>;
Pair operator+(const Pair& a, const Pair& b) { return {a[0] + b[0], a[1] + b[1]}; }
Pair operator-(const Pair& a, const Pair& b) { return {a[0] - b[0], a[1] - b[1]}; }

struct Query {
    int l, r, i;
    Pair search;
    bool ans;
    Query(int _l, int _r, Pair _search, int _i) {
        l = _l, r = _r, search = _search, i = _i;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    V<Pair> a(n+1); a[0] = {0, 0};
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') a[i+1] = a[i] + Pair{-1, 0};
        else if (s[i] == 'R') a[i+1] = a[i] + Pair{1, 0};
        else if (s[i] == 'U') a[i+1] = a[i] + Pair{0, 1};
        else if (s[i] == 'D') a[i+1] = a[i] + Pair{0, -1};
    }
    map<Pair, V<int>> m;
    for (int i = 0; i <= n; i++) {
        if (!m.contains(a[i])) m[a[i]] = V<int>();
        m[a[i]].push_back(i);
    }
    for (int i = 0; i < q; i++) {
        array<int, 2> search; cin >> search[0] >> search[1];
        int l, r; cin >> l >> r; l--, r--;
        Pair S = a[l], E = a[r+1];
        bool found = false;
        if (m.contains(search)) {
            // 0, l, search
            found |= m[search].front() <= l;
            // r+1, n, search
            found |= m[search].back() >= r+1;
        }
        Pair search2 = S + E - search;
        if (m.contains(search2)) {
            // l, r+1, search2
            auto it = lower_bound(begin(m[search2]), end(m[search2]), l);
            if (it != end(m[search2])) found |= *it <= r+1;
        }
        if (found) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
