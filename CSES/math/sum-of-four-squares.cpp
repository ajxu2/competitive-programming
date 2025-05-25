// created: 05-20-2025 Tue 04:13 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        V<array<int, 3>> stuff; // sums of two squares
        for (int i = 0; i * i <= n; i++)
            for (int j = i; i * i + j * j <= n; j++)
                stuff.push_back({i * i + j * j, i, j});
        sort(begin(stuff), end(stuff));
        stuff.erase(unique(begin(stuff), end(stuff), [](const array<int, 3>& a, const array<int, 3>& b) { return a[0] == b[0]; }), end(stuff));
        // now 2-pointer it
        int r = ssize(stuff) - 1;
        for (int l = 0; l <= r; l++) {
            while (r >= 0 && stuff[l][0] + stuff[r][0] > n)
                r--;
            if (r == -1) {
                cout << "uwu :3\n";
            } else if (stuff[l][0] + stuff[r][0] == n) {
                cout << stuff[l][1] << ' ' << stuff[l][2] << ' ' << stuff[r][1] << ' ' << stuff[r][2] << '\n';
                break;
            }
        }
    }
    return 0;
}
