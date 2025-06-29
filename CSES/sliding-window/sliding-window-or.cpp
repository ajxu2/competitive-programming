// created: 06-14-2025 Sat 06:27 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2")

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;
    V<int> stuff(n);
    stuff[0] = x;
    for (int i = 1; i < n; i++)
        stuff[i] = ((ll)a * stuff[i-1] + b) % c;
    int ans = 0;
    for (int i = 0; i < 30; i++) {
        // calc for this bit
        int bits_in_window = 0, on = 0;
        for (int j = 0; j < k; j++)
            bits_in_window += (stuff[j] >> i) & 1;
        on ^= bits_in_window > 0;
        for (int j = k; j < n; j++) {
            bits_in_window += (stuff[j] >> i) & 1;
            bits_in_window -= (stuff[j-k] >> i) & 1;
            on ^= bits_in_window > 0;
        }
        ans ^= on << i;
    }
    cout << ans << '\n';
    return 0;
}
