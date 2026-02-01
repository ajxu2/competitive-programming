// created: 01-24-2026 Sat 07:18 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct Point {
    int x, y;
    int dir() const {
        if (y == 0)
            return x > 0 ? 0 : 2;
        else if (y > 0)
            return 1;
        else
            return 3;
    }
    ll cross(const Point& o) const {
        return (ll)x * o.y - (ll)y * o.x;
    }
    bool operator<(const Point& o) const {
        int d1 = dir(), d2 = o.dir();
        if (d1 == d2)
            return cross(o) > 0;
        return d1 < d2;
    }
};
Point normalize(const Point& a) {
    int g = gcd(a.x, a.y);
    return {a.x / g, a.y / g};
}
ostream& operator<<(ostream& s, const Point& a) {
    return s << "(" << a.x << ", " << a.y << ")";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    V<Point> a(n);
    for (auto& [x, y] : a)
        cin >> x >> y;
    map<Point, int> m;
    for (Point i : a)
        m[normalize(i)]++;
    map<Point, int> p;
    int sum = 0;
    for (auto [pt, cnt] : m) {
        sum += cnt;
        p[pt] = sum;
    }
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        Point al = normalize(a[l]), ar = normalize(a[r]);
        auto itl = p.find(al), itr = p.find(ar);
        int ps1 = itr == begin(p) ? 0 : prev(itr)->second;
        int ps2 = itl->second;
        if (ps2 <= ps1)
            ps2 += n;
        cout << ps2 - ps1 << '\n';
    }
    return 0;
}
