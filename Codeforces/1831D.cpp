// created: 06-15-2023 Thu 05:44 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<int> a(n), b(n);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    V<map<int, ll>> freq(n+1);
    for (int i = 0; i < n; i++) freq[a[i]][b[i]]++;
    ll ans = 0;
    for (int i = 1; i * i <= 2 * n; i++) {
        for (pair<int, ll> j : freq[i]) {
            int other = i * i - j.first;
            if (other < j.first) break;
            if (other == j.first) ans += j.second * (j.second - 1) / 2;
            else if (freq[i].count(other)) ans += j.second * freq[i][other];
        }
        for (int j = i+1; j <= min(n, 2*n/i); j++) {
            int small = i, big = j;
            if (freq[small].size() > freq[big].size()) swap(small, big);
            for (pair<int, ll> k : freq[small]) {
                int other = i * j - k.first;
                if (other <= 0) break;
                if (freq[big].count(other)) ans += k.second * freq[big][other];
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
