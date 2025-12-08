// created: 12-04-2025 Thu 04:55 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int LOGMX = 20;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; ll k; cin >> n >> k;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    if (accumulate(begin(a), end(a), 0LL) <= k) {
        cout << "1\n";
        return 0;
    }
    V<int> b(n); // number of elts. can take before > k
    ll cur_sum = 0;
    int r = 0;
    for (int l = 0; l < n; l++) {
        while (cur_sum + a[r] <= k) {
            cur_sum += a[r];
            r++;
            if (r == n)
                r = 0;
        }
        b[l] = l < r ? r - l : n + r - l;
        cur_sum -= a[l];
    }
    V<V<ll>> lift(LOGMX, V<ll>(n));
    for (int i = 0; i < n; i++)
        lift[0][i] = b[i];
    for (int i = 1; i < LOGMX; i++) {
        for (int j = 0; j < n; j++) {
            int nxt = (j + lift[i-1][j]) % n;
            lift[i][j] = lift[i-1][j] + lift[i-1][nxt];
        }
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
        int taken = 0, cur_ans = 0;
        for (int j = LOGMX - 1; j >= 0; j--) {
            int cur = (i + taken) % n;
            if (taken + lift[j][cur] < n) {
                taken += lift[j][cur];
                cur_ans += 1 << j;
            }
        }
        cur_ans++;
        ans = min(ans, cur_ans);
    }
    cout << ans << '\n';
    return 0;
}
