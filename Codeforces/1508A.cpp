// created: 03-25-2022 Fri 08:31 AM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> a(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    vector<int> ptr(3, 0);
    string ans;
    while (ptr[0] < 2*n && ptr[1] < 2*n && ptr[2] < 2*n) {
        int numOne = 0;
        for (int i = 0; i < 3; i++) if (a[i][ptr[i]] == '1') numOne++;
        if (numOne >= 2) {
            for (int i = 0; i < 3; i++) if (a[i][ptr[i]] == '1') ptr[i]++;
            ans.push_back('1');
        } else {
            for (int i = 0; i < 3; i++) if (a[i][ptr[i]] == '0') ptr[i]++;
            ans.push_back('0');
        }
    }
    int maxString = max_element(ptr.begin(), ptr.end())-ptr.begin();
    int secondMax = (maxString+1) % 3;
    for (int i = 0; i < 3; i++) {
        if (i != maxString && ptr[i] >= ptr[secondMax]) secondMax = i;
    }
    while (ptr[secondMax] < 2*n) {
        ans.push_back(a[secondMax][ptr[secondMax]]);
        ptr[secondMax]++;
    }
    while (ans.length() < 3*n) ans.push_back('0');
    cout << ans << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
