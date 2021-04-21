// created: 04-21-2021 Wed 09:57 AM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    vector<long long> p(n+1);
    p[0] = 0;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i-1] + a[i-1];
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << p[r] - p[l] << "\n";
    }
    return 0;
}
