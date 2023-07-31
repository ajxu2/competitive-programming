// created: 07-31-2023 Mon 09:17 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

void solve() {
    // I HATE IMPL
    int n; cin >> n;
    map<array<int, 3>, V<int>> freq;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                array<int, 3> tmp = {0, 0, 0};
                tmp[i]++; tmp[j]++; tmp[k]++;
                freq[tmp];
            }
        }
    }
    string win = "win";
    for (int i = 1; i <= n; i++) {
        string tmp; cin >> tmp;
        array<int, 3> tmp2 = {0, 0, 0};
        for (char j : tmp) tmp2[win.find(j)]++;
        freq[tmp2].push_back(i);
    }
    ostringstream ss; // emerald block orz
    for (;;) {
        int upd = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                // i is 2, j is 0
                array<int, 3> fi = {0, 0, 0}, se = {0, 0, 0};
                fi[i] = 2; fi[j] = 0; fi[i^j^3] = 1; se[j] = 3;
                if (sz(freq[fi]) == 0) continue;
                if (sz(freq[se]) == 0) {
                    se[j] = 2; se[i^j^3] = 1;
                    if (sz(freq[se]) == 0) {
                        se[i^j^3] = 0; se[i] = 1;
                        if (sz(freq[se]) == 0) continue;
                    }
                }
                upd++;
                int bruh1 = freq[fi].back(), bruh2 = freq[se].back();
                ss << bruh1 << " " << win[i] << " " << bruh2 << " " << win[j] << "\n";
                freq[fi].pop_back(); freq[se].pop_back();
                fi[i]--; se[i]++; se[j]--; fi[j]++;
                freq[fi].push_back(bruh1); freq[se].push_back(bruh2);
            }
        }
        if (upd == 0) break;
    }
    int uwu = sz(freq[array<int, 3>{3, 0, 0}]);
    for (int i = 0; i < uwu; i++) {
        array<int, 3> ind;
        for (int j = 0; j < 3; j++) {
            array<int, 3> tmp = {0, 0, 0}; tmp[j] = 3;
            ind[j] = freq[tmp].back();
            freq[tmp].pop_back();
        }
        for (int j = 0; j < 3; j++) {
            ss << ind[j] << " " << win[j] << " " << ind[(j+1)%3] << " " << win[(j+1)%3] << "\n";
        }
    }
    string orz = ss.str();
    cout << count(orz.begin(), orz.end(), '\n') << "\n";
    cout << orz;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
