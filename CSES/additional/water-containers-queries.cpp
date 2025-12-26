// created: 12-23-2025 Tue 03:37 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // wlog a > b, then given some x, we can:
    // - add b (as long as x + b <= a)
    // - subtract b (as long as x >= b)
    // - add a - b (as long as x <= b) by putting x in b, fill a, move a b
    // then we can get any linear combination of a and b that is <= a, so gcd
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, x; cin >> a >> b >> x;
        cout << (x % gcd(a, b) == 0 && x <= a ? "YES" : "NO") << '\n';
    }
    return 0;
}
