#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s1, s2; cin >> s1 >> s2;
    vector<vector<int>> a1(18, vector<int>()), a2(18, vector<int>());
    for (int i = 0; i < s1.length(); i++) {
        a1[s1[i]-'a'].push_back(i);
    }
    for (int i = 0; i < s2.length(); i++) {
        a2[s2[i]-'a'].push_back(i);
    }
    vector<bool> szeq(18, false);
    for (int i = 0; i < 18; i++) szeq[i] = (a1[i].size() == a2[i].size());
    vector<vector<bool>> inverted(18, vector<bool>(18, false));
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 18; j++) {
            if (i == j || !szeq[i] || !szeq[j]) continue;
            // is this "inverted"? (i.e. a < b in 1 but a > b in 2)
            for (int k = 0; k < a1[i].size(); k++) {
                auto it1 = lower_bound(a1[j].begin(), a1[j].end(), a1[i][k]);
                auto it2 = lower_bound(a2[j].begin(), a2[j].end(), a2[i][k]);
                if (distance(a1[j].begin(), it1) != distance(a2[j].begin(), it2)) {
                    inverted[i][j] = true;
                    break;
                }
            }
        }
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        string query; cin >> query;
        bool works = true;
        for (int j = 0; j < query.length(); j++) {
            if (!szeq[query[j]-'a']) works = false;
        }
        for (int j = 0; j < query.length(); j++) {
            for (int k = j+1; k < query.length(); k++) {
                if (inverted[query[j]-'a'][query[k]-'a']) works = false;
            }
        }
        if (works) cout << "Y";
        else cout << "N";
    }
    cout << "\n";
    return 0;
}
