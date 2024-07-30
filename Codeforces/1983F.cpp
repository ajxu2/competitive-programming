// created: 07-07-2024 Sun 10:55 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; ll k; cin >> n >> k; k--;
    V<int> a(n);
    for (int& i : a) cin >> i;
    auto count_num_less = [&](int x) -> ll {
        ll cnt = 0;
        int r = 1;
        multiset<int> nums, xors;
        nums.insert(a[0]); nums.insert(a[1]); xors.insert(a[0] ^ a[1]);
        for (int l = 0; l < n-1; l++) {
            while (l == r || (r < n && *begin(xors) >= x)) {
                r++;
                if (r == n) break;
                // add a[r]
                auto it = nums.upper_bound(a[r]);
                if (it == end(nums)) xors.insert(*rbegin(nums) ^ a[r]);
                else if (it == begin(nums)) xors.insert(a[r] ^ *begin(nums));
                else {
                    auto pit = prev(it);
                    xors.erase(xors.find(*pit ^ *it));
                    xors.insert(*pit ^ a[r]); xors.insert(a[r] ^ *it);
                }
                nums.insert(a[r]);
            }
            cnt += n - r;
            // delete a[l]
            auto it = nums.find(a[l]);
            if (it == begin(nums)) xors.erase(xors.find(a[l] ^ *next(it)));
            else if (next(it) == end(nums)) xors.erase(xors.find(*prev(it) ^ a[l]));
            else {
                auto pit = prev(it), nit = next(it);
                xors.erase(xors.find(*pit ^ a[l])); xors.erase(xors.find(a[l] ^ *nit));
                xors.insert(*pit ^ *nit);
            }
            nums.erase(it);
        }
        return cnt;
    };
    int l = 0, r = 1 << 30;
    // find last i such that count_num_less(i) <= k
    while (l < r) {
        int mid = midpoint(l, r + 1);
        if (count_num_less(mid) <= k) l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
