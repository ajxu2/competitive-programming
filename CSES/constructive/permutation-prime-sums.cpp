// created: 08-11-2025 Mon 08:41 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    // generate primes up to 2*n
    V<bool> prime(2*n+1, true);
    prime[0] = false;
    prime[1] = false;
    V<int> primes;
    for (int i = 2; i <= 2 * n; i++) {
        if (prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= 2 * n; j += i)
                prime[j] = false;
        }
    }
    // idea: for any n, there exists 0 < i < n such that i+n is prime (bertrand)
    // so reverse the range from i to n, and repeat
    V<int> ans(n);
    iota(begin(ans), end(ans), 1);
    int cur = n;
    while (cur > 0) {
        int p = *upper_bound(begin(primes), end(primes), cur);
        int idx = p - cur - 1;
        reverse(begin(ans) + idx, begin(ans) + cur);
        cur = idx;
    }
    for (int i = 1; i <= n; i++)
        cout << i << " \n"[i == n];
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n-1];
    return 0;
}
