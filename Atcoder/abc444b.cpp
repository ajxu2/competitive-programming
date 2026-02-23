// created: 02-07-2026 Sat 07:46 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int digit_sum(int x) {
    int res = 0;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (digit_sum(i) == k)
            ans++;
    cout << ans << '\n';
    return 0;
}
