// created: 06-03-2023 Sat 04:39 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    V<int> sieve(1000001); // largest prime factor of the number
    iota(sieve.begin(), sieve.end(), 0);
    for (int i = 2; i <= 1000000; i++) {
        if (sieve[i] != i) continue;
        for (int j = 2*i; j <= 1000000; j += i) sieve[j] = i;
    }
    int x; cin >> x;
    int ans = 1e9;
    for (int i = x - sieve[x] + 1; i <= x; i++) {
        if (sieve[i] == i) continue;
        ans = min(ans, i - sieve[i] + 1);
    }
    cout << ans << "\n";
    return 0;
}
