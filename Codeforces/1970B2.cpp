// created: 12-17-2024 Tue 12:08 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // key idea: put first at (1, 1) and sweep right
    // each house's distance is just to the one in the column to its left
    // must do in decreasing order of distance
    cout << "YES\n"; // lol
    int n; cin >> n;
    V<array<int, 2>> a(n-1);
    cin >> a[0][0]; // garbage
    for (int i = 0; i < n-1; i++) {
        cin >> a[i][0];
        a[i][1] = i + 1;
    }
    sort(begin(a), end(a), greater<array<int, 2>>());
    V<array<int, 2>> ans(n);
    ans[0] = {1, 1};
    int lst = 1;
    for (int i = 0; i < n-1; i++) {
        int house = a[i][1];
        // place house at x-coord i+2
        ans[house][0] = i + 2;
        if (a[i][0] == 0) {
            if (i % 2 == 0) ans[house][1] = n;
            else ans[house][1] = 1;
        } else {
            int diff = a[i][0] - 1;
            if (i % 2 == 0) ans[house][1] = lst + diff;
            else ans[house][1] = lst - diff;
        }
        lst = ans[house][1];
    }
    V<int> ans2(n);
    ans2[0] = 0;
    ans2[a[0][1]] = a[0][0] == 0 ? a[0][1] : 0;
    for (int i = 1; i < n-1; i++) {
        ans2[a[i][1]] = a[i][0] == 0 ? a[i][1] : a[i-1][1];
    }
    for (const array<int, 2>& i : ans) cout << i[0] << ' ' << i[1] << '\n';
    for (int i = 0; i < n; i++) cout << ans2[i] + 1 << " \n"[i == n-1];
    return 0;
}
