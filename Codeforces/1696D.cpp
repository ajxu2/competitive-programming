// created: 07-20-2022 Wed 11:24 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
vector<int> a, pmin, pmax, smin, smax;

int dist(int l, int r, int depth, bool left) {
    // l = 0 or r = n-1
    // odd depth = min, even depth = max
    if (l == r) return 0;
    int split;
    if (left) {
        if (depth % 2 == 1) split = pmin[r];
        else split = pmax[r];
        return dist(0, split, depth+1, true) + 1;
    } else {
        if (depth % 2 == 1) split = smin[l];
        else split = smax[l];
        return 1 + dist(split, n-1, depth+1, false);
    }
}

void solve() {
    cin >> n;
    a = vector<int>(n);
    for (int& i : a) cin >> i;
    pmin = vector<int>(n, 0); pmax = vector<int>(n, 0);
    smin = vector<int>(n, n-1); smax = vector<int>(n, n-1);
    for (int i = 1; i < n; i++) {
        if (a[i] < a[pmin[i-1]]) pmin[i] = i;
        else pmin[i] = pmin[i-1];
        if (a[i] > a[pmax[i-1]]) pmax[i] = i;
        else pmax[i] = pmax[i-1];
    }
    for (int i = n-2; i >= 0; i--) {
        if (a[i] < a[smin[i+1]]) smin[i] = i;
        else smin[i] = smin[i+1];
        if (a[i] > a[smax[i+1]]) smax[i] = i;
        else smax[i] = smax[i+1];
    }
    int split = pmax[n-1]; // split by max
    cout << dist(0, split, 1, true) + dist(split, n-1, 1, false) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
