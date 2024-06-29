// created: 06-27-2024 Thu 01:56 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<int> a(n), b(n);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    int acnt = 0, bcnt = 0, bothp = 0, bothn = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1 && b[i] == 1) bothp++;
        else if (a[i] == -1 && b[i] == -1) bothn++;
        else if (a[i] < b[i]) bcnt += b[i];
        else acnt += a[i];
    }
    for (int i = 0; i < bothp; i++) (acnt < bcnt ? acnt : bcnt)++;
    for (int i = 0; i < bothn; i++) (acnt < bcnt ? bcnt : acnt)--;
    cout << min(acnt, bcnt) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
