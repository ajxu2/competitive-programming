// created: 02-16-2026 Mon 02:57 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;

void mod_sub(int& a, int b) {
    a -= b;
    if (a < 0)
        a += MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> f(n + 1, 0); // frequency map
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        f[x]++;
    }
    V<int> pow2(n + 1, 1);
    for (int i = 1; i <= n; i++)
        pow2[i] = pow2[i - 1] * 2 % MOD; 
    V<int> g(n + 1, 0); // number of subsets with gcd multiple of i
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i)
            g[i] += f[j];
        g[i] = pow2[g[i]] - 1;
    }
    for (int i = n; i >= 1; i--)
        for (int j = 2 * i; j <= n; j += i)
            mod_sub(g[i], g[j]);
    for (int i = 1; i <= n; i++)
        cout << g[i] << " \n"[i == n];
    return 0;
}
