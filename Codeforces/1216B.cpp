#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i+1;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
        ans += a[i][0]*(n-i-1)+1;
    }
    cout << ans << "\n";
    for (int i = n-1; i >= 0; i--) {
        cout << a[i][1] << " ";
    }
    cout << "\n";
    return 0;
}

