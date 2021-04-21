// created: 04-21-2021 Wed 10:11 AM

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin("stacking.in");
    ofstream cout("stacking.out");
    int n, k;
    cin >> n >> k;
    vector<int> e(n+2, 0);
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        e[l]++;
        e[r+1]--;
    }
    vector<int> a(n+1);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = a[i-1] + e[i];
    }
    sort(a.begin(), a.end());
    cout << a[(n+1)/2] << "\n";
    return 0;
}
