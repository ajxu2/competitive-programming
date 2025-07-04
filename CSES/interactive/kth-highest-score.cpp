// created: 07-01-2025 Tue 10:50 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'007;

int qry(bool finnish, int i) {
    cout << (finnish ? 'F' : 'S') << ' ' << i << endl;
    int res; cin >> res;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    auto better_qry = [n](bool finnish, int i) -> int {
        if (i <= 0)
            return INF;
        if (i > n)
            return -INF;
        return qry(finnish, i);
    };
    // out of all configurations of i finnish and k-i swedish,
    // find the right one using binary search
    int l = max(0, k - n), r = min(n, k) + 1;
    while (l < r) {
        int mid = midpoint(l, r);
        if (better_qry(true, mid) - better_qry(false, k - mid) > 0)
            l = mid + 1;
        else
            r = mid;
    }
    // l is the first position where F[l] - S[k-l] < 0
    int ans = max(better_qry(true, l), better_qry(false, k - l + 1));
    cout << "! " << ans << endl;
    return 0;
}
