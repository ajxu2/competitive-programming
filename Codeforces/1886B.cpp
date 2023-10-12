// created: 10-09-2023 Mon 09:43 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

double dist(double x1, double y1, double x2, double y2) {
    return hypot(x2-x1, y2-y1);
}

void solve() {
    double px, py, ax, ay, bx, by; cin >> px >> py >> ax >> ay >> bx >> by;
    double ao = dist(0, 0, ax, ay), bo = dist(0, 0, bx, by), ap = dist(px, py, ax, ay), bp = dist(px, py, bx, by);
    cout << setprecision(20) << min({max(ao, ap), max(bo, bp), max(dist(ax, ay, bx, by) / 2, max(min(ao, bo), min(ap, bp)))}) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
