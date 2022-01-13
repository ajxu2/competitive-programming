// created: 01-12-2022 Wed 05:44 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> pfx(n+1), sfx(n+1);
    // monotonic stack or something i am suffering
    // why do i have a habit of reading editorials before attempting problem
    stack<char> mono1;
    pfx[0] = 0;
    for (int i = 1; i <= n; i++) {
        pfx[i] = pfx[i-1];
        while (!mono1.empty() && mono1.top() > s[i-1]) mono1.pop();
        if (mono1.empty() || s[i-1] > mono1.top()) {
            mono1.push(s[i-1]);
            pfx[i]++;
        }
    }
    stack<char> mono2;
    sfx[n] = 0;
    for (int i = n-1; i >= 0; i--) {
        sfx[i] = sfx[i+1];
        while (!mono2.empty() && mono2.top() > s[i]) mono2.pop();
        if (mono2.empty() || s[i] > mono2.top()) {
            mono2.push(s[i]);
            sfx[i]++;
        }
    }
    // process queries
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << pfx[l-1] + sfx[r] << "\n";
    }
    return 0;
}
