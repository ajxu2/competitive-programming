// created: 05-25-2022 Wed 01:25 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    string s; cin >> s;
    int n = (int)s.length();
    int cntA = 0, cntB = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') cntA++;
        else cntB++;
    }
    bool works = true;
    if (a + c + d != cntA || b + c + d != cntB) {
        cout << "NO\n";
        return;
    }
    // split by adjacent
    vector<string> parts;
    string tmp; tmp.push_back(s[0]);
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            parts.push_back(tmp);
            tmp = "";
        }
        tmp.push_back(s[i]);
    }
    parts.push_back(tmp);
    sort(parts.begin(), parts.end(), [](const string& x, const string& y) {
        if (x.length() % 2 == y.length() % 2) return x.length() < y.length();
        return x.length() % 2 < y.length() % 2;
    });
    // first, get all the "evens" out of the way
    for (string& i : parts) {
        if (i.length() % 2 != 0) break;
        if (i[0] == 'A') {
            if (c >= i.length() / 2) {
                c -= i.length() / 2; i = "";
            } else {
                i = i.substr(c*2, i.length() - c*2); c = 0;
            }
        } else {
            if (d >= i.length() / 2) {
                d -= i.length() / 2; i = "";
            } else {
                i = i.substr(d*2, i.length() - d*2); d = 0;
            }
        }
    }
    for (string i : parts) {
        if (i == "") continue;
        // greedily match
        for (int j = 0; j < i.length();) {
            if (i.substr(j, 2) == "AB" && c > 0) {
                c--; j += 2;
            } else if (i.substr(j, 2) == "BA" && d > 0) {
                d--; j += 2;
            } else if (i[j] == 'A' && a > 0) {
                a--; j++;
            } else if (i[j] == 'B' && b > 0) {
                b--; j++;
            } else {
                cout << "NO\n"; return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
