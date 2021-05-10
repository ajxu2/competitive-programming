// created: 05-04-2021 Tue 09:37 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int recent;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cin >> recent;
        } else {
            int a;
            cin >> a;
            if (a != recent) {
                recent = a;
                ans++;
            }
        }
    }
    cout << ans << "\n";
    // 2:29 PagMan
    // *npesta*
    return 0;
}
