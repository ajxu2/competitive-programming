// created: 05-27-2023 Sat 03:27 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, k; cin >> n >> k;
    V<array<int, 2>> a(k+1);
    a[0] = {3, 3};
    for (int i = 1; i <= k; i++) cin >> a[i][0];
    for (int i = 1; i <= k; i++) cin >> a[i][1];
    for (int i = 0; i < k; i++) {
        if (a[i+1][1] - a[i][1] > a[i+1][0] - a[i][0]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    string ans = "orz", unused = "qwetyuipasdfghjklxcvbnm"; // lol
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        int charadd = a[i+1][0] - a[i][0], palinadd = a[i+1][1] - a[i][1];
        for (int j = 0; j < palinadd; j++) ans += unused[i];
        for (int j = 0; j < charadd-palinadd; j++, cnt++) ans += "orz"[cnt%3];
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve(); 
    return 0;
}
