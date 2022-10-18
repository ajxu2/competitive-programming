// created: 10-17-2022 Mon 11:50 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    bitset<100001> dp; dp[0] = 1;
    for (int i = 0; i < n; i++) { int a; cin >> a; dp |= (dp << a); }
    cout << dp.count() - 1 << "\n";
    for (int i = 1; i <= 100000; i++) if (dp[i]) cout << i << " ";
    return 0;
}
