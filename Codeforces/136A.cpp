// created: 05-04-2021 Tue 09:23 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[a[i]-1] = i+1;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n-1];
    }
    return 0;
}
