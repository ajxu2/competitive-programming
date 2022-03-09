// created: 03-07-2022 Mon 09:46 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k; cin >> n >> m >> k; 
    multiset<int> a, b;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        a.insert(tmp);
    }
    for (int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        b.insert(tmp);
    }
    int ans = 0;
    for (auto it = a.begin(); it != a.end(); it++) {
        auto apt = b.lower_bound((*it)-k);
        if (apt != b.end() && *apt <= (*it)+k) {
            ans++;
            b.erase(apt);
        }
    }
    cout << ans << "\n";
    return 0;
}
