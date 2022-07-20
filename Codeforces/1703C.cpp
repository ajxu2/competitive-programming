#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int b; cin >> b;
        string s; cin >> s;
        for (int j = 0; j < b; j++) {
            if (s[j] == 'D') a[i]++;
            else a[i]--;
        }
        a[i] = (a[i]+1000)%10;
    }
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n-1];
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
