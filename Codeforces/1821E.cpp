// created: 09-09-2023 Sat 01:53 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int k; cin >> k;
    string s; cin >> s;
    int n = sz(s);
    for (int i = 0; i < k; i++) {
        V<int> z; // zeroes
        z.push_back(-1);
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == '(') tmp++;
            else tmp--;
            if (tmp == 0) z.push_back(j);
        }
        int mx = 0, mxj = 0;
        for (int j = 0; j < sz(z)-1; j++) {
            if (z[j+1] - z[j] > mx) {
                mx = z[j+1] - z[j];
                mxj = j;
            }
        }
        s.erase(z[mxj+1], 1);
        s.insert(z[mxj]+2, 1, ')');
    }
    ll ans = (ll)n/2 * (n/2-1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') ans -= i;
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
