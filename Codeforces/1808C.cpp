// created: 07-02-2023 Sun 06:47 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

string check(int ld, int rd, string l, string r) {
    // check if it's possible to create number [l, r] using digits [ld, rd]
    // return a number with x in it if no number found
    //cout << "check(" << ld << ", " << rd << ", " << l << ", " << r << ")\n";
    int l0 = l[0] - '0', r0 = r[0] - '0';
    if (rd < l0 || ld > r0) return "x";
    if (l.length() == 1) {
        // find an intersection
        for (int i = l0; i <= r0; i++) {
            if (ld <= i && i <= rd) return to_string(i);
        }
    }
    if (l0 == r0) return to_string(l0) + check(ld, rd, l.substr(1), r.substr(1));
    for (int i = l0+1; i < r0; i++) {
        if (ld <= i && i <= rd) return string(l.length(), i + '0');
    }
    // edge cases
    string tmp = "x";
    if (ld <= l0 && l0 <= rd) tmp = to_string(l0) + check(ld, rd, l.substr(1), string(l.length()-1, '9'));
    if (tmp.find('x') == string::npos) return tmp;
    if (ld <= r0 && r0 <= rd) tmp = to_string(r0) + check(ld, rd, string(l.length()-1, '0'), r.substr(1));
    return tmp;
}

void solve() {
    string s1, s2; cin >> s1 >> s2;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9-i; j++) {
            if (s1.length() == s2.length()) {
                string tmp = check(j, j+i, s1, s2);
                if (tmp.find('x') == string::npos) {
                    cout << tmp << "\n";
                    return;
                }
            } else {
                string tmp = check(j, j+i, s1, string(s1.length(), '9'));
                if (tmp.find('x') == string::npos) {
                    cout << tmp << "\n";
                    return;
                }
                tmp = check(j, j+i, "1" + string(s2.length()-1, '0'), s2);
                if (tmp.find('x') == string::npos) {
                    cout << tmp << "\n";
                    return;
                }
                for (int k = s1.length()+1; k < s2.length(); k++) {
                    tmp = check(j, j+i, "1" + string(k-1, '0'), string(k, '9'));
                    if (tmp.find('x') == string::npos) {
                        cout << tmp << "\n";
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
