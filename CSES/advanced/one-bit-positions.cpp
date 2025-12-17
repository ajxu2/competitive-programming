// created: 12-17-2025 Wed 12:12 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
using C = complex<double>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = ssize(s);
    int len = 1;
    while (len < 2 * n)
        len *= 2;
    V<C> rou(len);
    for (int i = 0; i < len; i++)
        rou[i] = polar(1., 2 * numbers::pi / len * i);
    auto bit_reverse = [len](int x) {
        int res = 0;
        for (int i = 1; i < len; i *= 2) {
            res <<= 1;
            res += x & 1;
            x >>= 1;
        }
        return res;
    };
    auto dft = [&](V<C>& a) { // in-place
        for (int i = 0; i < len; i++) {
            int rev = bit_reverse(i);
            if (i < rev)
                swap(a[i], a[rev]);
        }
        for (int i = 1; i < len; i *= 2) {
            for (int j = 0; j < len; j += 2 * i) {
                // merge [j, j + i) and [j + i, j + 2i)
                for (int k = 0; k < i; k++) {
                    C x = a[j + k], y = a[j + i + k];
                    C w = rou[len / (2 * i) * k];
                    C nx = x + w * y, ny = x - w * y;
                    a[j + k] = nx; a[j + i + k] = ny;
                }
            }
        }
    };
    auto idft = [&](V<C>& a) {
        dft(a);
        reverse(begin(a) + 1, end(a));
        for (int i = 0; i < len; i++)
            a[i] /= len;
    };
    V<C> a(len, 0), b(len, 0);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] == '1';
        b[i] = s[n - 1 - i] == '1';
    }
    dft(a);
    dft(b);
    for (int i = 0; i < len; i++)
        a[i] *= b[i];
    idft(a);
    for (int i = 1; i < n; i++)
        cout << llround(a[i + n - 1].real()) << " \n"[i == n - 1];
    return 0;
}
