// created: 08-08-2021 Sun 01:31 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i+1;
    }
    sort(a.begin(), a.end());
    int r = n-1;
    for (int l = 0; l < n; l++) {
        while (l != r && a[l][0] + a[r][0] > x) {
            r--;
        }
        if (l == r) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        if (a[l][0] + a[r][0] == x) {
            cout << a[l][1] << " " << a[r][1] << "\n";
            return 0;
        }
    }
    return 0;
}
