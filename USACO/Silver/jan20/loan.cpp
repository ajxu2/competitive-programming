// created: 03-11-2022 Fri 01:36 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef LOCAL
    ifstream cin("loan.in");
    ofstream cout("loan.out");
#endif
    long long n, k, m; cin >> n >> k >> m;
    long long lo = 1, hi = 1e12, x;
    // range from [lo, hi]
    while (lo < hi) {
        x = (lo+hi+1)/2;
        // simulate for this value of x
        long long g = 0, day = 1;
        while ((n-g)/x > m && day <= k) {
            // instead of simulating one day at a time,
            // we'll skip ahead days whenever a chunk of days has the same g
            long long y = (n-g)/x;
            long long advance = min((n-x*y-g)/y+1, k-day+1);
            g += y*advance;
            day += advance;
        }
        g += (k-day+1)*m;
        if (g >= n) lo = x;
        else hi = x-1;
    }
    cout << lo << "\n";
    return 0;
}
