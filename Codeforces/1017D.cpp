// created: 07-04-2022 Mon 03:50 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    vector<int> cnt(1<<n, 0); // freq array
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        bitset<12> tmp(s);
        cnt[tmp.to_ulong()]++;
    }
    vector<vector<int>> ans(1<<n, vector<int>(101, 0)); // ans[i][j] = given string i, number in the multiset such that Wu exactly j
    for (int i = 0; i < 1<<n; i++) {
        for (int j = 0; j < 1<<n; j++) {
            bitset<12> a(i), b(j);
            bitset<12> c = ~(a^b);
            int wu = 0;
            for (int k = 0; k < n; k++) {
                if (c[k]) wu += w[n-k-1];
            }
            if (wu <= 100) ans[i][wu] += cnt[j];
        }
    }
    // psums
    for (int i = 0; i < 1<<n; i++) {
        for (int j = 1; j <= 100; j++) ans[i][j] += ans[i][j-1];
    }
    for (int i = 0; i < q; i++) {
        string s; int k; cin >> s >> k;
        bitset<12> tmp(s);
        cout << ans[tmp.to_ulong()][k] << "\n";
    }
    return 0;
}
