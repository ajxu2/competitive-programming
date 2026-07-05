// created: 06-27-2026 Sat 09:19 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int INF = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int h, w; cin >> h >> w;
    V<string> a(h);
    for (string& s : a)
        cin >> s;
    int min_row = INF, max_row = -INF, min_col = INF, max_col = -INF;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == '#') {
                min_row = min(min_row, i);
                max_row = max(max_row, i);
                min_col = min(min_col, j);
                max_col = max(max_col, j);
            }
        }
    }
    for (int i = min_row; i <= max_row; i++) 
        cout << a[i].substr(min_col, max_col - min_col + 1) << '\n';
    return 0;
}
