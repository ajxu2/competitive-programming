// created: 04-21-2021 Wed 02:15 PM

#include <bits/stdc++.h>
using namespace std;

long long solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> altsums(n+1);
    altsums[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            altsums[i] = altsums[i-1] - a[i];
        } else {
            altsums[i] = altsums[i-1] + a[i];
        }
    }
    vector<long long> pscores(n+1);
    pscores[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            pscores[i] = pscores[i-1] - i * a[i];
        } else {
            pscores[i] = pscores[i-1] + i * a[i];
        }
    }
    long long ans = 0;
    for (int i = 0; i < q; i++) {
        char qu;
        cin >> qu;
        if (qu == 'Q') {
            int l, r;
            cin >> l >> r;
            long long toAdd = 0;
            toAdd += (pscores[r] - pscores[l-1]);
            toAdd -= ((l-1) * (altsums[r] - altsums[l-1]));
            if (l % 2 == 0) {
                toAdd = 0 - toAdd;
            }
            ans += toAdd;
        } else {
            int x, v;
            cin >> x >> v;
            a[x] = v;
            for (int j = 1; j <= n; j++) {
                if (j % 2 == 0) {
                    altsums[j] = altsums[j-1] - a[j];
                } else {
                    altsums[j] = altsums[j-1] + a[j];
                }
            }
            for (int j = 1; j <= n; j++) {
                if (j % 2 == 0) {
                    pscores[j] = pscores[j-1] - j * a[j];
                } else {
                    pscores[j] = pscores[j-1] + j * a[j];
                }
            }
        }
    }
    return ans;
}

int main() {
    int TC;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": " << solve() << "\n";
    }
    return 0;
}
