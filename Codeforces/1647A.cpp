// created: 03-11-2022 Fri 08:34 AM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int sum = 0;
    string ans;
    if (n % 3 == 0 || n % 3 == 2) {
        for (int i = 0; sum < n; i++) {
            if (i % 2 == 0) {
                ans.push_back('2');
                sum += 2;
            } else {
                ans.push_back('1');
                sum += 1;
            }
        }
    } else {
        for (int i = 0; sum < n; i++) {
            if (i % 2 == 1) {
                ans.push_back('2');
                sum += 2;
            } else {
                ans.push_back('1');
                sum += 1;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve(); 
    return 0;
}
