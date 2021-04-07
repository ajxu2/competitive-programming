#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string r, b;
    cin >> r >> b;
    int redwin = 0;
    int bluewin = 0;
    for (int i = 0; i < n; i++) {
        if (r[i]>b[i]) redwin++;
        else if (b[i]>r[i]) bluewin++;
    }
    if (redwin > bluewin) cout << "RED\n";
    else if (bluewin > redwin) cout << "BLUE\n";
    else cout << "EQUAL\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
