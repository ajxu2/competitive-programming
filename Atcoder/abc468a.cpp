// created: 07-25-2026 Sat 08:52 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    int ans = 0;
    for (int i = 0; i < n - 2; i++)
        ans += (a[i] < a[i + 1] && a[i + 1] > a[i + 2]);
    cout << ans << '\n';
    return 0;
}
