// created: 07-05-2025 Sat 01:04 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 1'000'000'007;
const int LOGMX = 20;

void mod_sub(int& a, int b) {
    a -= b;
    if (a < 0)
        a += MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> pow2(n+1);
    pow2[0] = 1;
    for (int i = 1; i <= n; i++)
        pow2[i] = pow2[i-1] * 2 % MOD;
    V<int> sos(1 << LOGMX, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sos[x]++;
    }
    // count num subsets whose bitwise and is a superset
    for (int i = 0; i < LOGMX; i++)
        for (int j = 0; j < (1 << LOGMX); j++)
            if (((j >> i) & 1) == 0)
                sos[j] += sos[j ^ (1 << i)];
    for (int& i : sos)
        i = pow2[i];
    // inverse sum over superset dp
    for (int i = 0; i < LOGMX; i++)
        for (int j = 0; j < (1 << LOGMX); j++)
            if (((j >> i) & 1) == 0)
                mod_sub(sos[j], sos[j ^ (1 << i)]);
    for (int i = 0; i <= n; i++)
        cout << sos[i] << " \n"[i == n];
    return 0;
}
