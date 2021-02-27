#include <bits/stdc++.h>
using namespace std;

set<long long> powtwo;

void solve() {
    long long n;
    cin >> n;
    if (powtwo.count(n)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i <= 63; i++) {
        powtwo.insert(1LL << i);
    }
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}
