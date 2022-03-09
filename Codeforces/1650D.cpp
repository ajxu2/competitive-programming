// created: 03-08-2022 Tue 09:13 AM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> pos(n+1);
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        pos[tmp] = i+1;
    }
    vector<int> ans(n+1);
    for (int i = n; i >= 1; i--) {
        // we can immediately determine amt of cyclic shifts at i=n
        ans[i] = pos[i]-i;
        if (ans[i] < 0) ans[i] += i;
        for (int j = 1; j <= n; j++) {
            if (pos[j] <= i) pos[j] -= ans[i];
            if (pos[j] <= 0) pos[j] += i;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

int main() {
    int T; cin >> T;
    while (T--) solve(); 
    return 0;
}
