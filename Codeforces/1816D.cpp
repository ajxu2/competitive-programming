// created: 04-09-2023 Sun 01:22 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void t1(int x) {
    cout << "+ " << x << endl;
    int res; cin >> res;
    if (res == -2) exit(0);
}

int t2(int i, int j) {
    cout << "? " << i+1 << " " << j+1 << endl;
    int res; cin >> res;
    if (res == -2) exit(0);
    return res;
}

void solve() {
    int n; cin >> n;
    V<int> p1(n), p2(n);
    t1(n); t1(n+1);
    // find endpoint - largest distance from p[0]
    int mx = 0, mxi = -1;
    for (int i = 1; i < n; i++) {
        int res = t2(0, i);
        if (res > mx) {
            mx = res; mxi = i;
        }
    }
    V<int> d(n); // d[i] = dist from p[i] to endpt
    for (int i = 0; i < n; i++) {
        if (i == mxi) continue;
        d[i] = t2(i, mxi);
    }
    V<int> chain(n);
    for (int i = 0; i < n; i += 2) chain[i] = n-i/2;
    for (int i = 1; i < n; i += 2) chain[i] = (i+1)/2;
    // case 1, endpoint is n
    p1[mxi] = n;
    for (int i = 0; i < n; i++) {
        if (i == mxi) continue;
        p1[i] = chain[d[i]];
    }
    // case 2, endpoint is (n+1)/2
    reverse(chain.begin(), chain.end());
    p2[mxi] = (n+1)/2;
    for (int i = 0; i < n; i++) {
        if (i == mxi) continue;
        p2[i] = chain[d[i]];
    }
    cout << "! ";
    for (int i = 0; i < n; i++) cout << p1[i] << " ";
    for (int i = 0; i < n; i++) cout << p2[i] << " \n"[i == n-1];
    int res; cin >> res;
    if (res == -2) exit(0);
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
