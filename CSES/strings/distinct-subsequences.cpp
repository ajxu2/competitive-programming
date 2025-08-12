// created: 07-27-2025 Sun 11:25 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    array<int, 26> dp; // number of subsequences ending with each letter
    dp.fill(0);
    int total = 1;
    for (char i : s) {
        int new_subseq = (total - dp[i - 'a'] + MOD) % MOD;
        (dp[i - 'a'] += new_subseq) %= MOD;
        (total += new_subseq) %= MOD;
    }
    (total += MOD - 1) %= MOD;
    cout << total << '\n';
    return 0;
}
