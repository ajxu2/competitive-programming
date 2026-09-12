// created: 08-22-2026 Sat 07:03 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
template<class T> using V = vector<T>;

using Point = array<ld, 2>;
Point operator+(const Point& a, const Point& b) {
    return {a[0] + b[0], a[1] + b[1]};
}
Point operator-(const Point& a, const Point& b) {
    return {a[0] - b[0], a[1] - b[1]};
}
Point operator*(ld a, const Point& b) {
    return {a * b[0], a * b[1]};
}
Point operator/(const Point& a, ld b) {
    return {a[0] / b, a[1] / b};
}
ld cross(const Point& a, const Point& b) {
    return a[0] * b[1] - a[1] * b[0];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    V<Point> a(n);
    for (auto& [x, y] : a)
        cin >> x >> y;
    for (int i = 0; i < n; i++)
        a.push_back(a[i]);
    V<ld> crosses;
    for (int i = 0; i < 2 * n - 1; i++)
        crosses.push_back(cross(a[i], a[i + 1]));
    V<ld> p_crosses; // picross
    p_crosses.push_back(0);
    for (ld i : crosses)
        p_crosses.push_back(p_crosses.back() + i);
    V<Point> coms;
    for (int i = 0; i < 2 * n - 1; i++)
        coms.push_back(cross(a[i], a[i + 1]) * (a[i] + a[i + 1]));
    V<Point> p_coms;
    p_coms.push_back({0, 0});
    for (Point i : coms)
        p_coms.push_back(p_coms.back() + i);
    cout << fixed << setprecision(10);
    while (q--) {
        int u, v; cin >> u >> v; u--, v--;
        if (v < u)
            v += n;
        ld area = p_crosses[v] - p_crosses[u] + cross(a[v], a[u]);
        Point ans = p_coms[v] - p_coms[u] + cross(a[v], a[u]) * (a[v] + a[u]);
        ans = ans / (3 * area);
        cout << ans[0] << ' ' << ans[1] << '\n';
    }
    return 0;
}
