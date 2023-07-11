// created: 07-11-2023 Tue 10:13 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

void solve() {
    int n; cin >> n;
    // factor n
    V<int> fac;
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            fac.push_back(i);
            if (i != n/i) fac.push_back(n/i);
        }
    }
    sort(fac.begin(), fac.end());
    int mex = -1;
    for (int i = 0; i < sz(fac)-1; i++) {
        if (fac[i+1] - fac[i] > 1) {
            mex = fac[i] + 1; break;
        }
    }
    if (mex == -1) mex = fac.back() + 1;
    string s;
    for (int i = 0; i < n; i++) s.push_back((i%mex) + 'a');
    cout << s << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
