// created: 04-25-2026 Sat 08:53 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int h, w; cin >> h >> w;
    V<string> a(h);
    for (string& s : a)
        cin >> s;
    int ans = 0;
    for (int h1 = 0; h1 < h; h1++) {
        for (int h2 = h1; h2 < h; h2++) {
            for (int w1 = 0; w1 < w; w1++) {
                for (int w2 = w1; w2 < w; w2++) {
                    bool good = true;
                    for (int i = h1; i <= h2; i++) {
                        for (int j = w1; j <= w2; j++) {
                            good &= a[i][j] == a[h1 + h2 - i][w1 + w2 - j];
                        }
                    }
                    ans += good;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
