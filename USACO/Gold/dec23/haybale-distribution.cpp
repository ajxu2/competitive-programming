#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> x(n);
    for (int& i : x) cin >> i;
    sort(begin(x), end(x));
    V<ll> pfx(n+1), sfx(n+1);
    pfx[0] = 0;
    for (int i = 1; i <= n; i++) pfx[i] = pfx[i-1] + x[i-1];
    sfx[n] = 0;
    for (int i = n-1; i >= 0; i--) sfx[i] = sfx[i+1] + x[i];
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        int cand = (ll)b * n / (a+b);
        ll ans = LLONG_MAX;
        for (int j = max(cand-2, 0); j <= min(cand+2, n-1); j++) {
            ll distleft = (ll)j * x[j] - pfx[j], distright = sfx[j+1] - (ll)(n-1-j) * x[j];
            ans = min(ans, a * distleft + b * distright);
        }
        cout << ans << "\n";
    }
    return 0;
}
