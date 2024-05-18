// created: 05-17-2024 Fri 10:44 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }
using cc = complex<double>;

V<cc> roots;

cc w(int n, int k) { return roots[sz(roots) / n * k]; }

V<cc> dft(V<cc> a) {
    // A(x) = P1(x^2) + xP2(x^2)
    if (sz(a) == 1) return a;
    V<cc> p1(sz(a) >> 1), p2(sz(a) >> 1);
    for (int i = 0; i < sz(a); i++) {
        if (i % 2 == 0) p1[i >> 1] = a[i];
        else p2[i >> 1] = a[i];
    }
    p1 = dft(p1); p2 = dft(p2);
    V<cc> res(sz(a));
    for (int i = 0; i < sz(a) >> 1; i++) {
        cc wi = w(sz(a), i);
        res[i] = p1[i] + wi * p2[i];
        res[i + (sz(a) >> 1)] = p1[i] - wi * p2[i];
    }
    return res;
}

V<cc> idft(V<cc> a) {
    V<cc> res = dft(a);
    reverse(res.begin() + 1, res.end());
    for (cc& i : res) i /= sz(a);
    return res;
}

V<cc> convolute(V<cc> a, V<cc> b) {
    a = dft(a); b = dft(b);
    V<cc> res(sz(a));
    for (int i = 0; i < sz(a); i++) res[i] = a[i] * b[i];
    return idft(res);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int k, n, m; cin >> k >> n >> m;
    int sz = 1; while (sz < 2 * k + 1) sz <<= 1;
    V<cc> a(sz), b(sz);
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp; a[tmp] += 1;
    }
    for (int i = 0; i < m; i++) {
        int tmp; cin >> tmp; b[tmp] += 1;
    }
    roots.resize(sz);
    for (int i = 0; i < sz; i++) roots[i] = polar(1., 2 * numbers::pi / sz * i);
    V<cc> res = convolute(a, b);
    for (int i = 2; i <= 2 * k; i++) {
        cout << llround(res[i].real()) << " \n"[i == 2 * k];
    }
    return 0;
}
