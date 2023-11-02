// created: 11-01-2023 Wed 11:00 AM
 
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }
 
const int MX = 1'000'000;
 
int main() {
    V<int> sieve(MX+1, 0);
    iota(begin(sieve), end(sieve), 0);
    for (int i = 2; i <= MX; i++) {
        if (sieve[i] != i) continue;
        for (int j = 2 * i; j <= MX; j += i) sieve[j] = i;
    }
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    ll ans = 0;
    V<int> fac(MX+1, 0);
    for (int i : a) {
        set<int> pfs;
        while (i != 1) {
            pfs.insert(sieve[i]); i /= sieve[i];
        }
        V<int> pf(begin(pfs), end(pfs));
        int k = sz(pf);
        for (int j = 0; j < (1<<k); j++) {
            int cnt = 0, mul = 1;
            for (int l = 0; l < k; l++) {
                if (j&(1<<l)) {
                    cnt++;
                    mul *= pf[l];
                }
            }
            if (cnt % 2 == 0) ans += fac[mul];
            else ans -= fac[mul];
            fac[mul]++;
        }
    }
    cout << ans << "\n";
	return 0;
}
