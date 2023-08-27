// created: 08-24-2023 Thu 08:55 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

int q(int l, int r) {
    if (l == r) return 0;
    cout << "? " << l << " " << r << endl;
    int x; cin >> x;
    if (x == -1) exit(0);
    return x;
}

int meow(int l, int r) {
    // the index of the max element in [l, r]
    if (l == r) return l;
    int mid = (l + r) / 2;
    int ml = meow(l, mid), mr = meow(mid+1, r);
    if (q(ml, mr) - q(ml+1, mr) == mr - ml) return ml;
    return mr;
}

void solve() {
    int n; cin >> n;
    int x = meow(1, n);
    cout << "! " << x << endl;
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
