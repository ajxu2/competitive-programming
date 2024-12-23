// created: 12-22-2024 Sun 11:44 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    V<pair<int, bool>> qs(q);
    for (pair<int, bool>& i : qs) {
        int s; string pm; cin >> s >> pm;
        s--;
        i.first = s;
        i.second = pm == "+";
    }
    V<V<int>> gap(n, V<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            V<pair<int, bool>> qs_restricted;
            for (const pair<int, bool>& k : qs) {
                if (k.first == i || k.first == j) {
                    qs_restricted.push_back(k);
                }
            }
            int cur_gap = 0;
            for (const pair<int, bool>& k : qs_restricted) {
                int s = k.first; bool pm = k.second;
                if (s == i && pm) cur_gap++;
                else if (s == j && !pm) cur_gap--;
                gap[i][j] = max(gap[i][j], cur_gap);
            }
        }
    }
    V<int> extension(n, 0);
    for (const pair<int, bool>& i : qs) {
        int s = i.first; bool pm = i.second;
        if (pm) extension[s]++;
    }
    V<V<ll>> dp(1<<n, V<ll>(n, INF));
    for (int i = 0; i < n; i++) dp[1<<i][i] = extension[i];
    for (int i = 0; i < (1 << n); i++) {
        if (popcount((unsigned)i) <= 1) continue;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) == 0) continue;
            unsigned new_mask = i ^ (1 << j);
            for (int k = 0; k < n; k++) {
                if ((new_mask & (1 << k)) == 0) continue;
                dp[i][j] = min(dp[i][j], dp[new_mask][k] - extension[k] + gap[k][j] + extension[j]);
            }
        }
    }
    cout << n + *min_element(begin(dp[(1<<n)-1]), end(dp[(1<<n)-1])) << '\n';
    return 0;
}
