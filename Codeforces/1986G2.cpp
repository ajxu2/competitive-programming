// created: 06-24-2024 Mon 02:27 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MAXN = 500'000;
array<V<int>, MAXN+1> fac;

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    V<V<int>> bruh(n+1), bruhh(n+1);
    for (int i = 0; i < n; i++) {
        int num = a[i], den = i + 1;
        int g = gcd(num, den); num /= g; den /= g;
        bruh[den].push_back(num);
        bruhh[num].push_back(den);
    }
    ll ans = 0;
    V<int> cnt(n+1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) for (int k : bruhh[j]) cnt[k]++;
        for (int j : bruh[i]) for (int k : fac[j]) ans += cnt[k];
        for (int j = i; j <= n; j += i) for (int k : bruhh[j]) cnt[k]--;
    }
    ans -= ssize(bruh[1]); ans >>= 1;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 1; i <= MAXN; i++) {
        for (int j = i; j <= MAXN; j += i) fac[j].push_back(i);
    }
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
