// created: 02-19-2022 Sat 05:41 PM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> a(n);
    multiset<string> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        // can this be the first string?
        // can't pair with itself or before
        s.erase(s.find(a[i]));
        bool exists = false;
        if (a[i].length() == 1) {
            // we're done
            exists = true;
        } else if (a[i].length() == 2) {
            // "ab" can pair with "ba" or "?ba"
            string tmp = a[i];
            swap(tmp[0], tmp[1]);
            if (tmp == a[i]) exists = true; // palindrome already
            if (s.find(tmp) != s.end()) exists = true;
            else {
                tmp.insert(tmp.begin(), ' ');
                for (char j = 'a'; j <= 'z'; j++) {
                    tmp[0] = j;
                    if (s.find(tmp) != s.end()) exists = true;
                }
            }
        } else if (a[i].length() == 3) {
            // "abc" can pair with "ba" or "cba"
            string tmp = a[i];
            swap(tmp[0], tmp[2]);
            if (tmp == a[i]) exists = true; // palindrome already
            if (s.find(tmp) != s.end()) exists = true;
            else {
                tmp.erase(tmp.begin());
                if (s.find(tmp) != s.end()) exists = true;
            }
        }
        if (exists) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}

int main() {
    int TC; cin >> TC;
    while (TC--) solve();
    return 0;
}
