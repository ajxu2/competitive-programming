// created: 05-20-2025 Tue 11:53 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MAXN = 200'000;
const int MOD = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // prime factorization stuff
    array<int, MAXN + 1> fac; // fac[i] = largest prime factor
    fac.fill(-1);
    for (int i = 2; i <= MAXN; i++) {
        if (fac[i] != -1)
            continue;
        for (int j = i; j <= MAXN; j += i)
            fac[j] = i;
    }
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) {
        cin >> i; i--;
    }
    map<int, int> ans;
    V<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (vis[i])
            continue;
        // get cycle length
        int len = 0, ptr = i;
        while (!vis[ptr]) {
            vis[ptr] = true;
            ptr = a[ptr];
            len++;
        }
        // prime factorize
        map<int, int> pf;
        while (len > 1) {
            pf[fac[len]]++;
            len /= fac[len];
        }
        for (auto [p, e] : pf)
            ans[p] = max(ans[p], e);
    }
    ll real_ans = 1;
    for (auto [p, e] : ans) {
        for (int i = 0; i < e; i++) {
            real_ans *= p;
            real_ans %= MOD;
        }
    }
    cout << real_ans << '\n';
    return 0;
}
