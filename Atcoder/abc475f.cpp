// created: 09-12-2026 Sat 08:31 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int h, w; cin >> h >> w;
    V<string> a(h);
    for (string& i : a)
        cin >> i;
    if (h > w) {
        V<string> b(w, string(h, 0));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                b[j][i] = a[i][j];
        a = b;
        swap(h, w);
    }
    ll ans = 1;
    for (int h1 = 0; h1 < h; h1++) {
        V<int> num_blank(w, 0);
        V<int> nonzero_psum(w + 1, 0);
        for (int h2 = h1; h2 < h; h2++) {
            for (int i = 0; i < w; i++)
                num_blank[i] += a[h2][i] == '.';
            for (int i = 1; i <= w; i++)
                nonzero_psum[i] = nonzero_psum[i - 1] + (num_blank[i - 1] != 0);
            int last_top = -1, last_bot = -1;
            for (int i = 0; i < w; i++) {
                if (a[h1][i] == '.')
                    last_top = i;
                if (a[h2][i] == '.')
                    last_bot = i;
                if (num_blank[i] == 0)
                    continue;
                ans += nonzero_psum[min(last_top, last_bot) + 1];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
