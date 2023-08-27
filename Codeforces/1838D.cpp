// created: 08-26-2023 Sat 09:27 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    V<bool> a(n);
    for (int i = 0; i < n; i++) a[i] = s[i] == ')';
    set<int> l, r;
    for (int i = 0; i < n-1; i++) {
        if (!a[i] && !a[i+1]) l.insert(i);
        else if (a[i] && a[i+1]) r.insert(i);
    }
    for (int i = 0; i < q; i++) {
        int x; cin >> x; x--;
        a[x] = !a[x];
        if (x > 0) {
            l.erase(x-1); r.erase(x-1);
            if (!a[x-1] && !a[x]) l.insert(x-1);
            else if (a[x-1] && a[x]) r.insert(x-1);
        }
        if (x < n-1) {
            l.erase(x); r.erase(x);
            if (!a[x] && !a[x+1]) l.insert(x);
            else if (a[x] && a[x+1]) r.insert(x);
        }
        // now check if this new config is ok
        if (n % 2 == 1) cout << "NO\n";
        else if (a[0] || !a[n-1]) cout << "NO\n";
        else if (l.empty() && r.empty()) cout << "YES\n";
        else if (l.empty() || r.empty()) cout << "NO\n";
        else if (*l.begin() < *r.begin() && *l.rbegin() < *r.rbegin()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
