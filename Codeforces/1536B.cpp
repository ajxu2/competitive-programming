// created: 06-06-2021 Sun 09:47 AM

#include <bits/stdc++.h>
using namespace std;

vector<string> a;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (string i : a) {
        if (s.find(i) == string::npos) {
            cout << i << "\n";
            return;
        }
    }
}

int main() {
    for (int i = 'a'; i <= 'z'; i++) {
        string tmp;
        tmp.push_back(i);
        a.push_back(tmp);
    }
    for (int i = 'a'; i <= 'z'; i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            string tmp;
            tmp.push_back(i);
            tmp.push_back(j);
            a.push_back(tmp);
        }
    }
    for (int i = 'a'; i <= 'z'; i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            for (int k = 'a'; k <= 'z'; k++) {
                string tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(k);
                a.push_back(tmp);
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
