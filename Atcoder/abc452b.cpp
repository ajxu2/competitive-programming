// created: 04-04-2026 Sat 09:07 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int h, w; cin >> h >> w;
    for (int i = 0; i < h; i++) {
        string row(w, '#');
        if (i != 0 && i != h - 1) {
            for (int j = 1; j < w - 1; j++)
                row[j] = '.';
        }
        cout << row << '\n';
    }
    return 0;
}
