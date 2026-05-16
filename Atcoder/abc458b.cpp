// created: 05-16-2026 Sat 09:20 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int h, w; cin >> h >> w;
    auto in_bounds = [&](int i, int j) -> bool {
        return 0 <= i && i < h && 0 <= j && j < w;
    };
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int ans = 0;
            ans += in_bounds(i, j + 1);
            ans += in_bounds(i, j - 1);
            ans += in_bounds(i + 1, j);
            ans += in_bounds(i - 1, j);
            cout << ans << " \n"[j == w - 1];
        }
    }
    return 0;
}
