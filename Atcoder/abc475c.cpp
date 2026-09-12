// created: 09-12-2026 Sat 09:36 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, s; ll l; cin >> n >> s >> l; s--;
    V<int> a(n - 1);
    for (int& i : a)
        cin >> i;
    int ans = 0;
    for (int i = 0; i <= s; i++) {
        ll so_far = 0;
        for (int j = i; j < s; j++)
            so_far += 2 * a[j];
        if (so_far > l)
            continue;
        int best = s;
        while (best < n - 1 && so_far + a[best] <= l) {
            so_far += a[best];
            best++;
        }
        ans = max(ans, best - i + 1);
    }
    for (int i = s; i < n; i++) {
        ll so_far = 0;
        for (int j = s; j < i; j++)
            so_far += 2 * a[j];
        if (so_far > l)
            continue;
        int best = s;
        while (best > 0 && so_far + a[best - 1] <= l) {
            so_far += a[best - 1];
            best--;
        }
        ans = max(ans, i - best + 1);
    }
    cout << ans << '\n';
    return 0;
}
