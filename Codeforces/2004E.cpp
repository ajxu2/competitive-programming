// created: 12-23-2024 Mon 10:12 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MX = 10'000'005;
array<int, MX> G;

void solve() {
    int n; cin >> n;
    int nimber = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        nimber ^= G[a];
    }
    cout << (nimber == 0 ? "Bob" : "Alice") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // precalculate grundy numbers by sieving
    // grundy numbers of primes are increasing natural numbers
    // grundy numbers of everything else are grundy of smallest prime factor
    G.fill(-1);
    G[0] = 0; G[1] = 1;
    int primes_seen = 0;
    for (int i = 2; i < MX; i++) {
        if (G[i] != -1) continue;
        primes_seen++;
        G[i] = i == 2 ? 0 : primes_seen;
        for (int j = 2 * i; j < MX; j += i) {
            if (G[j] == -1) G[j] = G[i];
        }
    }
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
