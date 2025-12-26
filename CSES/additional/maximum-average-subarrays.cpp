// created: 12-25-2025 Thu 03:05 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

using Point = array<ll, 2>;
ll cross(Point A, Point B) {
    return A[0] * B[1] - A[1] * B[0];
}
Point operator-(const Point& A, const Point& B) {
    return {A[0] - B[0], A[1] - B[1]};
}
ll cross(Point A, Point B, Point C) {
    return cross(B - A, C - A);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    // take prefix sum then consider lower convex hull
    V<ll> p(n + 1, 0);
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i - 1];
    V<Point> hull;
    hull.push_back({0, 0});
    for (int i = 1; i <= n; i++) {
        Point P = {i, p[i]};
        while (ssize(hull) >= 2 && cross(end(hull)[-1], end(hull)[-2], P) >= 0)
            hull.pop_back();
        cout << i - hull.back()[0] << " \n"[i == n];
        hull.push_back(P);
    }
    return 0;
}
