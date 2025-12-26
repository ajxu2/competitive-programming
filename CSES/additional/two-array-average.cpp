// created: 12-25-2025 Thu 03:46 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

using Point = array<ll, 2>;
ll cross(Point A, Point B) {
    return A[0] * B[1] - A[1] * B[0];
}
Point& operator+=(Point& A, const Point& B) {
    A[0] += B[0];
    A[1] += B[1];
    return A;
}
Point operator+(Point A, const Point& B) {
    return A += B;
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
    V<ll> a(n), b(n);
    for (ll& i : a)
        cin >> i;
    for (ll& i : b)
        cin >> i;
    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
    }
    // convex hull of minkowski sum or something
    V<Point> hull_a, hull_b;
    hull_a.push_back({1, a[0]});
    for (int i = 1; i < n; i++) {
        Point P = {i + 1, a[i]};
        while (ssize(hull_a) >= 2 && cross(end(hull_a)[-1], end(hull_a)[-2], P) <= 0)
            hull_a.pop_back();
        hull_a.push_back(P);
    }
    hull_b.push_back({1, b[0]});
    for (int i = 1; i < n; i++) {
        Point P = {i + 1, b[i]};
        while (ssize(hull_b) >= 2 && cross(end(hull_b)[-1], end(hull_b)[-2], P) <= 0)
            hull_b.pop_back();
        hull_b.push_back(P);
    }
    V<Point> diff_a, diff_b;
    for (int i = 0; i < ssize(hull_a) - 1; i++)
        diff_a.push_back(hull_a[i + 1] - hull_a[i]);
    for (int i = 0; i < ssize(hull_b) - 1; i++)
        diff_b.push_back(hull_b[i + 1] - hull_b[i]);
    Point sum_a = hull_a[0], sum_b = hull_b[0], best_a = sum_a, best_b = sum_b;
    int ptr_a = 0, ptr_b = 0;
    while (ptr_a < ssize(diff_a) || ptr_b < ssize(diff_b)) {
        if (ptr_a == ssize(diff_a))
            sum_b += diff_b[ptr_b++];
        else if (ptr_b == ssize(diff_b))
            sum_a += diff_a[ptr_a++];
        else if (cross(diff_a[ptr_a], diff_b[ptr_b]) < 0)
            sum_a += diff_a[ptr_a++];
        else
            sum_b += diff_b[ptr_b++];
        Point P = sum_a + sum_b;
        if (cross(best_a + best_b, P) > 0) {
            best_a = sum_a;
            best_b = sum_b;
        }
    }
    cout << best_a[0] << ' ' << best_b[0] << '\n';
    return 0;
}
