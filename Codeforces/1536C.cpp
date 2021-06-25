// created: 06-06-2021 Sun 10:11 AM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    map<array<int, 2>, int> ratio;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int d = 0, k = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D') {
            d++;
        } else {
            k++;
        }
        array<int, 2> search = {d/gcd(d, k), k/gcd(d, k)};
        if (!ratio.count(search)) {
            ratio[search] = 1;
        } else {
            ratio[search]++;
        }
        cout << ratio[search] << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
