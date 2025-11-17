// created: 11-16-2025 Sun 09:48 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

void iadd(int& a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

void isub(int& a, int b) {
    a -= b;
    if (a < 0)
        a += MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    map<int, int> mp;
    int lst = -1;
    V<int> dp(n + 1); // answer for first i elements
    dp[0] = 1;
    int sum = 1;
    for (int i = 0; i < n; i++) {
        auto it = mp.find(a[i]);
        if (it != end(mp) && lst < it->second) {
            for (int j = lst; j < it->second; j++)
                isub(sum, dp[j + 1]);
            lst = it->second;
        }
        dp[i + 1] = sum;
        iadd(sum, dp[i + 1]);
        mp[a[i]] = i;
    }
    cout << dp[n] << '\n';
    return 0;
}
