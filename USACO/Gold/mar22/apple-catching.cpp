// created: 08-04-2022 Thu 03:37 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Pt {
    int q, t, x, n;
    bool operator<(const Pt& y) {
        if (t == y.t) return x < y.x;
        return t < y.t;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<Pt> a(n);
    for (Pt& i : a) {
        cin >> i.q >> i.t >> i.x >> i.n;
        // rotate 45 degrees ccw in t, x plane
        int t2 = i.t - i.x, x2 = i.t + i.x;
        i.t = t2; i.x = x2;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    map<int, int> m; // (x, n)
    for (int i = 0; i < n; i++) {
        // sweep through a
        if (a[i].q == 1) m[a[i].x] += a[i].n;
        else {
            auto c = m.upper_bound(a[i].x);
            if (c == m.begin()) continue; // no cow can catch
            c--;
            if (a[i].n > c->second) {
                // more apples than cows
                ans += c->second;
                a[i].n -= c->second;
                m.erase(c);
                i--;
            } else if (a[i].n < c->second) {
                // more cows than apples
                ans += a[i].n;
                c->second -= a[i].n;
            } else {
                // cows and apples equal
                ans += a[i].n;
                m.erase(c);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
