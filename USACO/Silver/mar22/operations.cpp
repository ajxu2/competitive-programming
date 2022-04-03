#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    vector<int> p(s.length()+1, 0);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'C') p[i+1] = 1;
        if (s[i] == 'O') p[i+1] = 2;
        if (s[i] == 'W') p[i+1] = 3;
    }
    for (int i = 1; i <= s.length(); i++) p[i] ^= p[i-1];
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        if ((p[b] ^ p[a-1]) == 1) cout << "Y";
        else cout << "N";
    }
    cout << "\n";
    return 0;
}
