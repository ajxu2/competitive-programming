// created: 07-25-2026 Sat 08:48 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> p(n), q(n);
    for (int& i : p)
        cin >> i, i--;
    for (int& i : q)
        cin >> i, i--;
    V<int> a(n);
    iota(begin(a), end(a), 0);
    int ans = 0;
    do {
        ans += (p < a && a < q);
    } while (next_permutation(begin(a), end(a)));
    cout << ans << '\n';
    return 0;
}
