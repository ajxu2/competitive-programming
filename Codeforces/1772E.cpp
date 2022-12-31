// created: 12-31-2022 Sat 11:56 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    int f = 0, s = 0, both = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x != i && x != (n - i + 1)) both++;
        else if (x != i) f++;
        else if (x != (n - i + 1)) s++;
    }
    // simulate game
    for (int i = 0; ; i++) {
        if (i % 2 == 0) {
            // first person's turn
            if (f > 0) f--;
            else if (both == 1 && s == 0) {
                cout << "Tie\n";
                return;
            } else both--;
            if (f + both == 0) {
                cout << "First\n";
                return;
            }
        } else {
            // second person's turn
            if (s > 0) s--;
            else if (both == 1 && f == 0) {
                cout << "Tie\n";
                return;
            } else both--;
            if (s + both == 0) {
                cout << "Second\n";
                return;
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
