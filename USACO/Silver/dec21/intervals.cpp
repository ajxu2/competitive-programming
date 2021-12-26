// created: 12-24-2021 Fri 08:21 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a(n);
    vector<int> afreq(m+1, 0), bfreq(m+1, 0);
    vector<long long> p(2*m+2, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        // add entries to frequency table
        afreq[a[i][0]]++;
        bfreq[a[i][1]]++;
    }
    // iterate over all pairs in frequency table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            p[i+j] += ((long long)afreq[i]*afreq[j]);
            p[i+j+1] -= ((long long)bfreq[i]*bfreq[j]);
        }
    }
    // prefix sums
    for (int i = 1; i <= 2*m+1; i++) {
        p[i] += p[i-1];
    }
    for (int i = 0; i <= 2*m; i++)  {
        cout << p[i] << "\n";
    }
    return 0;
}
