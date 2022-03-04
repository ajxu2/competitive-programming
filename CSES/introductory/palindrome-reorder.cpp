// created: 03-03-2022 Fri 2:29 PM
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s; cin >> s;
    vector<int> a(26, 0);
    for (char i : s) a[i-'A']++;
    int odd = 0;
    for (int i = 0; i < 26; i++) if (a[i] % 2 == 1) odd++;
    if (odd > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    string ans;
    for (int i = 0; i < 26; i++) {
        if (a[i] % 2 == 1) continue;
        for (int j = 0; j < (a[i]/2); j++) {
            ans.push_back(i+'A');
        }
    }
    for (int i = 0; i < 26; i++) {
        if (a[i] % 2 == 1) {
            for (int j = 0; j < a[i]; j++) {
                ans.push_back(i+'A');
            }
        }
    }
    for (int i = 25; i >= 0; i--) {
        if (a[i] % 2 == 1) continue;
        for (int j = 0; j < (a[i]/2); j++) {
            ans.push_back(i+'A');
        }
    }
    cout << ans << "\n";
    return 0;
}
