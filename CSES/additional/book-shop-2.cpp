// created: 10-18-2024 Fri 12:08 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    V<int> h(n), s(n), k(n);
    for (int& i : h) cin >> i;
    for (int& i : s) cin >> i;
    for (int& i : k) cin >> i;
    V<array<int, 2>> books;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; sum + (1 << j) < k[i]; j++) {
            books.push_back({(1 << j) * h[i], (1 << j) * s[i]});
            sum += 1 << j;
        }
        books.push_back({(k[i] - sum) * h[i], (k[i] - sum) * s[i]});
    }
    V<ll> dp(x+1, 0);
    for (array<int, 2> i : books) {
        for (int j = x; j - i[0] >= 0; j--) {
            dp[j] = max(dp[j], dp[j - i[0]] + i[1]);
        }
    }
    cout << dp[x] << '\n';
    return 0;
}
