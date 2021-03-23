#include <bits/stdc++.h>
using namespace std;

const string FILENAME = "div7";

int main() {
#ifndef LOCAL
    freopen((FILENAME + ".in").c_str(), "r", stdin);
    freopen((FILENAME + ".out").c_str(), "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<long long>> modsums(7);
    long long temp1 = 0, temp2;
    modsums[0].push_back(0);
    for (int i = 1; i <= n; i++) {
        cin >> temp2;
        temp1 += temp2;
        modsums[temp1 % 7].push_back(i);
    }
    long long temp3, temp4;
    long long ans = 0;
    for (int i = 0; i < 7; i++) {
        if (!modsums[i].empty()) {
            temp3 = *max_element(modsums[i].begin(), modsums[i].end());
            temp4 = *min_element(modsums[i].begin(), modsums[i].end());
            ans = max(ans, temp3 - temp4);
        }
    }
    cout << ans << "\n";
    return 0;
}

