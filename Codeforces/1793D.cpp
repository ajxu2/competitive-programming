// created: 02-25-2023 Sat 04:31 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> p(n), q(n);
    for (int& i : p) cin >> i;
    for (int& i : q) cin >> i;
    V<int> posp(n+1), posq(n+1);
    for (int i = 0; i < n; i++) {
        posp[p[i]] = i;
        posq[q[i]] = i;
    }
    ll ans = 0; int cnt = 1;
    // count # with mex 1
    for (int i = 0; i < n; i++) {
        if (p[i] != 1 && q[i] != 1) {
            ans += cnt; cnt++;
        } else cnt = 1;
    }
    int mn = 1e9, mx = -1;
    for (int i = 2; i <= n; i++) {
        // count # with mex i; get all (1..i-1), avoid all i
        mn = min(mn, min(posp[i-1], posq[i-1])), mx = max(mx, max(posp[i-1], posq[i-1]));
        if (mn <= posp[i] && posp[i] <= mx || mn <= posq[i] && posq[i] <= mx) continue;
        int l, r; // # of left bounds, # of right bounds
        if (posp[i] < mn && posq[i] < mn) {
            l = mn - max(posp[i], posq[i]), r = n - mx;
        } else if (posp[i] > mx && posq[i] > mx) {
            l = mn + 1, r = min(posp[i], posq[i]) - mx;
        } else {
            l = mn - min(posp[i], posq[i]), r = max(posp[i], posq[i]) - mx;
        }
        ans += (ll)l*r;
    }
    ans++; // mex n+1
    cout << ans << "\n";
    return 0;
}
