// created: 07-07-2024 Sun 09:46 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    array<V<int>, 3> a;
    for (int i = 0; i < 3; i++) {
        a[i] = V<int>(n);
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }
    ll threshold = (accumulate(begin(a[0]), end(a[0]), 0LL) + 2) / 3;
    array<int, 6> ans; ans.fill(-1);
    for (int pref = 0; pref < 3; pref++) {
        for (int suf = 0; suf < 3; suf++) {
            if (pref == suf) continue;
            int other = 3 - pref - suf;
            int idx1 = 0; ll sum1 = 0;
            while (idx1 < n && sum1 < threshold) sum1 += a[pref][idx1++];
            int idx2 = n-1; ll sum2 = 0;
            while (idx2 >= 0 && sum2 < threshold) sum2 += a[suf][idx2--];
            ll sum3 = 0;
            for (int i = idx1; i <= idx2; i++) sum3 += a[other][i];
            if (sum3 >= threshold) {
                ans[2*pref] = 1;
                ans[2*pref+1] = idx1;
                ans[2*suf] = idx2 + 2;
                ans[2*suf+1] = n;
                ans[2*other] = idx1 + 1;
                ans[2*other+1] = idx2 + 1;
            }
        }
    }
    if (ans[0] == -1) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < 6; i++) cout << ans[i] << " \n"[i == 5];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
