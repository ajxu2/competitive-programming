// created: 06-22-2022 Wed 01:39 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    string s, t; cin >> s >> t;
    vector<int> ps(t.length()+1), pt(t.length()+1);
    ps[0] = -1; pt[0] = s.length();
    int ptr = 0;
    for (int i = 0; i < t.length(); i++) {
        while (s[ptr] != t[i]) ptr++;
        ps[i+1] = ptr;
        ptr++;
    }
    ptr = s.length()-1;
    for (int i = 0; i < t.length(); i++) {
        while (s[ptr] != t[t.length()-i-1]) ptr--;
        pt[i+1] = ptr;
        ptr--;
    }
    int ans = 0;
    for (int i = 0; i <= t.length(); i++) {
        ans = max(ans, pt[t.length()-i] - ps[i] - 1);
    }
    cout << ans << "\n";
    return 0;
}
