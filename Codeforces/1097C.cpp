// created: 01-24-2022 Mon 11:05 AM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    multiset<array<int, 2>> a;
    int bothZero = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int l = 0, r = 0;
        for (int j = 0; j < (int)s.length(); j++) {
            // count number of unclosed left/right parens
            if (s[j] == '(') l++;
            else {
                if (l > 0) l--;
                else r++;
            }
        }
        if (l == 0 && r == 0) bothZero++;
        else a.insert({l, r});
    }
    int ans = bothZero/2;
    while (!a.empty()) {
        array<int, 2> tmp = *(a.begin());
        // to match another one, must be in format: {a, 0} and {0, a}
        if (tmp[0] == 0 || tmp[1] == 0) {
            if (a.find({tmp[1], tmp[0]}) != a.end()) {
                a.erase(a.find({tmp[1], tmp[0]}));
                ans++;
            }
        }
        a.erase(a.begin());
    }
    cout << ans << "\n";
    return 0;
}
