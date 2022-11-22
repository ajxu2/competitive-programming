// created: 11-22-2022 Tue 01:14 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1'000'000'007;

int main() {
#ifndef LOCAL
    ifstream cin("help.in");
    ofstream cout("help.out");
#endif
    int n; cin >> n;
    vector<array<int, 2>> a(n);
    for (array<int, 2>& i : a) cin >> i[0] >> i[1];
    vector<int> p(2*n+2, 0); // the number of segments that some point belongs to
    for (array<int, 2> i : a) {
        p[i[0]]++; p[i[1]+1]--;
    }
    for (int i = 1; i < 2*n+2; i++) p[i] += p[i-1];
    vector<int> powtwo(n+1, 1);
    for (int i = 1; i <= n; i++) powtwo[i] = powtwo[i-1] * 2 % MOD;
    // for each starting point, add 2^((n-1)-(number segments-1))
    int ans = 0;
    for (array<int, 2> i : a) ans = (ans + powtwo[n-p[i[0]]]) % MOD;
    cout << ans << "\n";
    return 0;
}
