// created: 07-20-2023 Thu 02:00 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    string s; cin >> s;
    V<int> order; // lower numbers in the order have higher priority
    set<int> se;
    for (int i = 0; i < n; i++) se.insert(i);
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r; l--, r--;
        auto it = se.lower_bound(l);
        while (it != se.end() && *it <= r) {
            order.push_back(*it);
            it = se.erase(it);
        }
    }
    int cnt = count(s.begin(), s.end(), '1');
    string opt(n, '0');
    for (int i = 0; i < min(cnt, sz(order)); i++) opt[order[i]] = '1';
    int ans = 0;
    for (int i = 0; i < n; i++) if (s[i] == '0' && opt[i] == '1') ans++;
    for (int i = 0; i < q; i++) {
        int x; cin >> x; x--;
        if (s[x] == '0') {
            s[x] = '1';
            if (opt[x] == '1') ans--;
            if (cnt < sz(order)) {
                opt[order[cnt]] = '1';
                if (s[order[cnt]] == '0') ans++;
            }
            cnt++;
        } else {
            s[x] = '0';
            if (opt[x] == '1') ans++;
            cnt--;
            if (cnt < sz(order)) {
                opt[order[cnt]] = '0';
                if (s[order[cnt]] == '0') ans--;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
