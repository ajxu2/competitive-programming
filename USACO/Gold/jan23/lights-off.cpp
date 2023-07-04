// created: 07-03-2023 Mon 08:00 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

int t, n;
bool dp[61][1<<20]; // dp[i][j] = starting 0 switches, possible to turn lights (j) off in i moves

inline int rshift(int x) {
    return (x >> 1) + (x & 1) * (1 << (n-1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t >> n;
    dp[0][0] = true;
    for (int i = 1; i <= 3*n; i++) {
        // calculate iterations for this mask
        int mask[20];
        mask[0] = 0;
        for (int j = 0; j < i; j++) mask[0] ^= (1 << (n-1-(j%n)));
        for (int j = 1; j < n; j++) mask[j] = rshift(mask[j-1]);
        for (int j = 0; j < (1<<n); j++) {
            for (int k = 0; k < n; k++) dp[i][j] |= dp[i-1][j^mask[k]];
        }
    }
    for (int i = 0; i < t; i++) {
        string lb, sb; cin >> lb >> sb;
        int l = stoi(lb, 0, 2), s = stoi(sb, 0, 2);
        int mask = 0;
        for (int j = 0; j <= 3*n; j++) {
            // test if this j possible
            if (dp[j][l^mask]) {
                cout << j << "\n";
                break;
            }
            mask = rshift(mask);
            mask ^= s;
        }
    }
    return 0;
}
