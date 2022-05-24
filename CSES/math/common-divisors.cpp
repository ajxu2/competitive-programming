// created: 05-23-2022 Mon 02:29 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    array<int, 1000001> cnt = {0};
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int j = 1; j*j <= x; j++) {
            if (x % j == 0) {
                cnt[j]++;
                if (j*j != x) cnt[x/j]++;
            }
        }
    }
    for (int i = 1000000; i >= 1; i--) {
        if (cnt[i] >= 2) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}
