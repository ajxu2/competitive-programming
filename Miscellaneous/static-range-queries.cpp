/*
 * Static Range Queries
 *
 * There is an array A of length 1e9, initially containing all zeroes.
 *
 * First perform N updates of the following form:
 * Given integers l, r, and v, add v to all values in the array
 * in the interval [l,r).
 *
 * Then, answer Q queries of the following form:
 * Given integers l and r, print the sum of the values in the array
 * in the interval [l,r).
 *
 * INPUT
 * Line 1: The two space-separated integers N and Q (1<=N,Q<=1e5)
 * Lines 2..N+1: Each line contains three space-separated integers l, r, and v, 
 * corresponding to an update (0<=l<r<=1e9, v<=1e4).
 * Lines N+2..N+Q+1: Each line contains two space-separated integers l and r, 
 * corresponding to a query (0<=l<r<=1e9).
 *
 * OUTPUT
 * Print Q lines, the answers to the queries in the same order 
 * as given in the input.
 */

// created: 08-07-2021 Sat 09:13 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<array<int, 2>> diff;
    for (int i = 0; i < n; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        diff.push_back({l, v});
        diff.push_back({r, -v});
    }
    map<int, int> a;
    a[0] = 0;
    for (int i = 0; i < 2*n; i++) {
        if (a.count(diff[i][0])) {
            a[diff[i][0]] += diff[i][1];
        } else {
            a[diff[i][0]] = diff[i][1];
        }
    }
    for (auto it = next(a.begin()); it != a.end(); it++) {
        it->second += prev(it)->second;
    }
    map<int, long long> p;
    p[0] = 0;
    for (auto it = next(a.begin()); it != a.end(); it++) {
        p[it->first] = prev(it)->second;
        p[it->first] *= it->first - prev(it)->first;
        p[it->first] += p[prev(it)->first];
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        auto lit = p.lower_bound(l), rit = prev(p.upper_bound(r));
        long long ans;
        if (distance(lit, rit) < 0) {
            ans = r - l;
            ans *= a[rit->first];
        } else {
            ans = rit->second - lit->second;
            long long lerror = lit->first - l, rerror = r - rit->first;
            if (lit != p.begin()) {
                ans += lerror * a[prev(lit)->first];
            }
            ans += rerror * a[rit->first];
        }
        cout << ans << "\n";
    }
    return 0;
}
