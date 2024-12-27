// created: 12-27-2024 Fri 12:31 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, q; cin >> n >> q;
    V<int> freq(n+1, 0);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        freq[a]++;
    }
    V<int> pf(n+1, 0);
    pf[0] = freq[0];
    for (int i = 1; i <= n; i++) pf[i] = pf[i-1] + freq[i];
    auto get_num_in_range = [&](int l, int r) -> int {
        // get number of numbers in [l, r]
        return l == 0 ? pf[r] : pf[r] - pf[l-1];
    };
    // calculate the answer for all queries 1 to n
    V<int> ans(n+1);
    auto get_num_most_k_mod_x = [&](int x, int k) -> int {
        // get number of numbers that are at most k (mod x)
        int res = 0;
        for (int i = 0; i <= n; i += x) {
            res += get_num_in_range(i, min(i + k, n));
        }
        return res;
    };
    for (int x = 1; x <= n; x++) {
        // binary search on the median
        int l = 0, r = x - 1;
        while (l < r) {
            int mid = midpoint(l, r);
            if (get_num_most_k_mod_x(x, mid) >= n / 2 + 1) r = mid;
            else l = mid + 1;
        }
        ans[x] = l;
    }
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        cout << ans[x] << " \n"[i == q-1];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
