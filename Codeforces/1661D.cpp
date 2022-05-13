// created: 05-12-2022 Thu 02:34 PM

#include <bits/stdc++.h>
using namespace std;

// what did i just type

int main() {
    int n, k; cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<long long> level(n);
    long long sum = 0, cnt = 0;
    for (int i = n-1; i >= 0; i--) {
        int origk = k;
        sum -= cnt;
        a[i] -= sum;
        if (i < k) k = i+1;
        if (a[i] > 0) level[i] = (a[i]+k-1)/k;
        else level[i] = 0;
        sum += level[i]*k;
        if (i < k) k = origk;
        cnt += level[i];
        if (i+k < n) cnt -= level[i+k];
    }
    long long ans = 0;
    for (long long i : level) ans += i;
    cout << ans << "\n";
    return 0;
}
