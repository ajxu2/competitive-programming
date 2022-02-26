#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    // get the path from a to 1
    set<array<long long, 2>> apath;
    apath.insert({a, 0});
    long long tmp = 0;
    while (a != 1) {
        tmp++;
        if (a % 2 == 0) a /= 2;
        else a++;
        apath.insert({a, tmp});
    }
    // get the path from 1 to b
    set<array<long long, 2>> bpath;
    bpath.insert({b, 0});
    tmp = 0;
    while (b != 1) {
        tmp++;
        if (b % 2 == 0) b /= 2;
        else b--;
        bpath.insert({b, tmp});
    }
    long long ans = 1e18;
    // get the shortest path between a and b
    for (array<long long, 2> i : apath) {
        auto it = bpath.lower_bound({i[0], 0});
        if (it == bpath.end()) continue;
        array<long long, 2> j = *it;
        ans = min(ans, i[1]+j[1]+j[0]-i[0]);
    }
    cout << ans << "\n";
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
    return 0;
}
