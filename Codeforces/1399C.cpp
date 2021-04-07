#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a;
        int bruh, sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> bruh;
            sum += bruh;
            a.push_back(bruh);
        }
        int ans = 0;
        multiset<int> test;
        for (int i = 0; i <= sum*2/n+100; i++) {
            int pairs = 0;
            for (auto& j : a) {
                test.insert(j);
            }
            while (!test.empty()) {
                auto it = test.begin();
                bruh = *it;
                test.erase(it);
                if (test.find(i-bruh) != test.end()) {
                    pairs++;
                    test.erase(test.find(i-bruh));
                }
            }
            ans = max(pairs, ans);
            test.clear();
        }
        cout << ans << "\n";
    }
    return 0;
}
