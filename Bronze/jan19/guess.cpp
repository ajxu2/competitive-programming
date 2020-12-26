#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)((x).size())

int main() {
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<string> > things(n);
    string t; int k;
    for (int i = 0; i < n; i++) {
        cin >> t >> k;
        for (int j = 0; j < k; j++) {
            cin >> t;
            things[i].push_back(t);
        }
    }
    int ans = 0;
    set<string> s;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            s.clear();
            for (int k = 0; k < sz(things[i]); k++) {
                s.insert(things[i][k]);
            }
            for (int k = 0; k < sz(things[j]); k++) {
                s.insert(things[j][k]);
            }
            ans = max(ans, sz(things[i]) + sz(things[j]) - sz(s));
        }
    }
    cout << ans+1 << "\n";
    return 0;
}
