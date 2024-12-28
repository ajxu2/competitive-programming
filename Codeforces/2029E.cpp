// created: 12-27-2024 Fri 08:37 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MX = 400'005;
array<int, MX> divisor; // smallest nontrivial divisor or -1

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    V<int> primes;
    for (int i : a) {
        if (divisor[i] == -1) {
            primes.push_back(i);
        }
    }
    switch (ssize(primes)) {
        case 0:
            cout << "2\n";
            break;
        case 1:
            {
                int p = primes[0];
                bool ok = true;
                for (int i : a) {
                    if (i != p && i != 2 * p && i - divisor[i] < 2 * p) {
                        ok = false;
                    }
                }
                cout << (ok ? p : -1) << '\n';
                break;
            }
        default:
            cout << "-1\n";
            break;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // precompute elements of divisor using sieve
    divisor.fill(-1);
    for (int i = 2; i < MX; i++) {
        if (divisor[i] != -1) continue;
        for (int j = 2 * i; j < MX; j += i) {
            if (divisor[j] == -1) divisor[j] = i;
        }
    }
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
