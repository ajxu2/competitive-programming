// created: 01-17-2026 Sat 07:06 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; ll x; cin >> n >> k >> x;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    sort(begin(a), end(a));
    int ptr = 0; ll sum = 0;
    int ans = INF;
    for (int i = 0; i < n; i++) {
        while (ptr < n && sum < x)
            sum += a[ptr++];
        if (sum >= x && ptr - i <= k - i)
            ans = min(ans, n - i);
        sum -= a[i];
    }
    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}
