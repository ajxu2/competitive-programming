// created: 02-24-2023 Fri 11:01 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'000;

void solve() {
    int n, c; cin >> n >> c;
    V<int> a(n);
    for (int& i : a) cin >> i;
    V<array<ll, 2>> best(n);
    for (int i = 0; i < n; i++) best[i] = {min(a[i]+i+1, a[i]+n-i), i};
    sort(best.begin(), best.end());
    V<int> pos(n);
    for (int i = 0; i < n; i++) pos[best[i][1]] = i;
    V<array<ll, 2>> pbest = best;
    for (int i = 1; i < n; i++) pbest[i][0] += pbest[i-1][0];
    array<ll, 2> search = {c, INF};
    int ans = 0;
    // iterate through all portals we could take as our first one
    for (int i = 0; i < n; i++) {
        // take this one as first portal
        int cost2 = c - (a[i]+i+1);
        if (cost2 < 0) continue;
        // BS on prefix sum array
        search = {cost2, INF};
        int thisAns = upper_bound(pbest.begin(), pbest.end(), search) - pbest.begin() + 1;
        if (pos[i] < thisAns-1) {
            // recalculate
            search[0] += best[pos[i]][0];
            thisAns = upper_bound(pbest.begin(), pbest.end(), search) - pbest.begin();
        }
        ans = max(ans, thisAns);
    }
    cout << ans << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
