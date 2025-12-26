// created: 12-23-2025 Tue 12:19 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MAXN = 5000;
const int PI = 670; // haha six seven
const int MOD = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    array<int, MAXN + 1> sieve; // smallest prime divisor
    sieve.fill(-1);
    for (int i = 2; i <= MAXN; i++) {
        if (sieve[i] != -1)
            continue;
        sieve[i] = i;
        for (int j = 2 * i; j <= MAXN; j += i)
            if (sieve[j] == -1)
                sieve[j] = i;
    }
    array<int, MAXN + 1> lookup; // lookup[p] = number of primes less than p
    int cnt = 0;
    for (int i = 2; i <= MAXN; i++)
        if (sieve[i] == i)
            lookup[i] = cnt++;
    int n; cin >> n;
    V<bitset<PI>> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        while (x > 1) {
            int p = sieve[x];
            a[i][lookup[p]].flip();
            x /= p;
        }
    }
    // gaussian eliminate
    int pivoted = 0;
    for (int col = 0; col < PI; col++) {
        int row = -1;
        for (int i = pivoted; i < n; i++) {
            if (a[i][col]) {
                row = i;
                break;
            }
        }
        if (row == -1)
            continue;
        swap(a[row], a[pivoted]);
        for (int i = 0; i < n; i++)
            if (i != pivoted && a[i][col])
                a[i] ^= a[pivoted];
        pivoted++;
    }
    int ans = 1;
    for (int i = 0; i < n - pivoted; i++)
        (ans *= 2) %= MOD;
    cout << ans << '\n';
    return 0;
}
