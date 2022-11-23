// created: 10-15-2022 Sat 10:55 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(int B) {
    int n; cin >> n;
    vector<int> p(n), l(n), r(n), mn(n), mx(n), w(n);
    for (int i = 1; i < n; i++) {
        cin >> p[i]; p[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    int minR = *min_element(r.begin(), r.end()), maxL = *max_element(l.begin(), l.end());
    int mid = (minR + maxL) / 2;
    for (int i = 0; i < n; i++) w[i] = clamp(mid, l[i], r[i]); // FINALLY found a use for this new function!
    mn[0] = w[0];
    for (int i = 1; i < n; i++) mn[i] = min(mn[p[i]], w[i]);
    mx[0] = w[0];
    for (int i = 1; i < n; i++) mx[i] = max(mx[p[i]], w[i]);
    int ans = 0;
    for (int i = 1; i < n; i++) ans = max(ans, max(w[i] - mn[i], mx[i] - w[i]));
    cout << ans << "\n";
    if (B == 1) for (int i = 0; i < n; i++) cout << w[i] << " \n"[i == n-1];
}

int main() {
    int T, B; cin >> T >> B;
    while (T--) solve(B);
    return 0;
}
