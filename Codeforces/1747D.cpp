// created: 11-27-2022 Sun 07:17 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    vector<int> p(n+1, 0);
    for (int i = 1; i <= n; i++) p[i] = p[i-1] ^ a[i-1];
    vector<ll> ps(n+1, 0);
    for (int i = 1; i <= n; i++) ps[i] = ps[i-1] + a[i-1];
    map<int, int> odd, even;
    vector<int> lst(n+1, 0); // lst[i] has the latest index that is an odd dist. away & xorsum = 0
    even[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            if (odd.count(p[i])) lst[i] = odd[p[i]] + 1;
            even[p[i]] = i;
        } else {
            if (even.count(p[i])) lst[i] = even[p[i]] + 1;
            odd[p[i]] = i;
        }
    }
    //for (int i = 0; i <= n; i++) cout << lst[i] << " \n"[i == n];
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        if ((p[r] ^ p[l-1]) != 0) {
            cout << "-1\n";
        } else if (ps[r] - ps[l-1] == 0) {
            cout << "0\n";
        } else if ((r - l) % 2 == 0) {
            cout << "1\n";
        } else if (a[r-1] == 0 || a[l-1] == 0) {
            cout << "1\n";
        } else if (lst[r] > l) {
            cout << "2\n";
        } else cout << "-1\n";
    }
    return 0;
}
