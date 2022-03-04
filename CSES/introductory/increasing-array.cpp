#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    long long ans = 0;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1]) {
            ans += (a[i-1] - a[i]);
            a[i] = a[i-1];
        }
    }
    cout << ans << "\n";
    return 0;
}
