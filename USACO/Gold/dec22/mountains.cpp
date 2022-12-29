#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Frac {
    ll n, d;
    Frac(ll _n, ll _d) { n = _n; d = _d; }
    bool operator<(const Frac& a) const { return n * a.d < d * a.n; }
    bool operator>(const Frac& a) const { return n * a.d > d * a.n; }
    bool operator==(const Frac& a) const { return n * a.d == d * a.n; }
    bool operator<=(const Frac& a) const { return n * a.d <= d * a.n; }
    bool operator>=(const Frac& a) const { return n * a.d >= d * a.n; }
};

ostream& operator<<(ostream& s, const Frac& a) { s << a.n << "/" << a.d; return s; }
template<class T> ostream& operator<<(ostream& s, const set<T>& se) {
    s << "{";
    for (T i : se) s << i << ", ";
    s << "}";
    return s;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    // calculate preliminary answer
    vector<set<int>> s(n-1); // the mountains that each mountain can see
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        Frac mx(a[i+1] - a[i], 1);
        s[i].insert(i+1);
        for (int j = i+2; j < n; j++) {
            Frac slope(a[j] - a[i], j - i);
            if (slope > mx || slope == mx) {
                mx = slope; s[i].insert(j);
            }
        }
        ans += s[i].size();
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y; x--;
        for (int j = 0; j < x; j++) {
            // calculate which mountains are "shadowed" by this change
            Frac initial(a[x] - a[j], x - j), newer(a[x] - a[j] + y, x - j);
            auto it = s[j].upper_bound(x);
            while (it != s[j].end() && newer > Frac(a[*it] - a[j], *it - j)) {
                it = s[j].erase(it); ans--;
            }
            // calculate if this mountain becomes visible
            it = s[j].lower_bound(x);
            if (it == s[j].begin()) continue;
            it--;
            Frac prev(a[*it] - a[j], *it - j);
            if (prev > initial && prev <= newer) {
                ans++;
                s[j].insert(x);
            }
        }
        a[x] += y;
        if (x != n-1) {
            ans -= s[x].size();
            s[x].clear();
            // reupdate
            Frac mx(a[x+1] - a[x], 1);
            s[x].insert(x+1);
            for (int j = x+2; j < n; j++) {
                Frac slope(a[j] - a[x], j - x);
                if (slope > mx || slope == mx) {
                    mx = slope; s[x].insert(j);
                }
            }
            ans += s[x].size();
        }
        cout << ans << "\n";
    }
}
