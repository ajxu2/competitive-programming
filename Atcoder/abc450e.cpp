// created: 03-24-2026 Tue 01:09 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string x, y; cin >> x >> y;
    array<int, 26> fx, fy;
    fx.fill(0); fy.fill(0);
    for (char i : x)
        fx[i - 'a']++;
    for (char i : y)
        fy[i - 'a']++;
    array<V<int>, 26> cf; // cf[i][j] = number of character i in first j chars of y + x
    for (int i = 0; i < 26; i++) {
        int cur = 0;
        cf[i].push_back(cur);
        for (char j : y + x) {
            if (j - 'a' == i)
                cur++;
            cf[i].push_back(cur);
        }
    }
    V<ll> fib;
    array<V<ll>, 26> fib_f; // fib_f[i][j] = number of character i in S_j
    fib.push_back(ssize(x));
    fib.push_back(ssize(y));
    while (fib.back() < INF)
        fib.push_back(end(fib)[-1] + end(fib)[-2]);
    for (int i = 0; i < 26; i++) {
        fib_f[i].push_back(fx[i]);
        fib_f[i].push_back(fy[i]);
        for (int j = 0; j < ssize(fib) - 2; j++)
            fib_f[i].push_back(end(fib_f[i])[-1] + end(fib_f[i])[-2]);
    }
    auto solve = [&](ll x, char c) -> ll {
        // count occurrences of c in the first x chars
        ll res = 0;
        for (int i = ssize(fib) - 1; i >= 2; i--) {
            if (x >= fib[i]) {
                res += fib_f[c - 'a'][i];
                x -= fib[i];
            }
        }
        res += cf[c - 'a'][x];
        return res;
    };
    int q; cin >> q;
    while (q--) {
        ll l, r; char c; cin >> l >> r >> c;
        cout << solve(r, c) - solve(l - 1, c) << '\n';
    }
    return 0;
}
