// created: 10-16-2022 Sun 12:08 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    // USACO --> USAMO
    // precompute all (i choose j)/(2^i)
    vector<vector<double>> ch(1001, vector<double>(1001));
    ch[0][0] = 1;
    for (int i = 1; i <= 1000; i++) {
        ch[i][0] = ch[i-1][0]/2; ch[i][i] = ch[i-1][i-1]/2;
        for (int j = 1; j < i; j++) ch[i][j] = (ch[i-1][j-1] + ch[i-1][j])/2;
    }
    int T, K; cin >> T >> K;
    T--; // add sample case back later
    double ev = 0.5*T, a = 0, b = 0; // E_i = aE_(i-1) + b
    int skip = 1;
    for (int i = 1; i < K; i += skip) {
        // compute a and b
        a = 0, b = 0;
        for (int j = 0; j <= T; j++) {
            if (j <= ev) a += ch[T][j];
            else b += ch[T][j] * j;
        }
        // BS on first index such that floor(EV) changes
        int l = 1, r = K - i;
        while (l < r) {
            skip = (l+r)/2;
            double v = pow(a, skip) * ev + b * (pow(a, skip) - 1) / (a - 1);
            if ((int)v == (int)ev) l = skip + 1;
            else r = skip;
        }
        skip = l;
        ev = pow(a, skip) * ev + b * (pow(a, skip) - 1) / (a - 1);
    }
    cout << setprecision(20) << ev+1 << "\n";
    return 0;
}
