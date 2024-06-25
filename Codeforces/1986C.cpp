// created: 06-23-2024 Sun 10:01 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    V<int> ind(m); for (int& i : ind) { cin >> i; i--; }
    string c; cin >> c;
    set<int> se(begin(ind), end(ind));
    sort(begin(c), end(c));
    int ptr = 0;
    for (int i : se) s[i] = c[ptr++];
    cout << s << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
