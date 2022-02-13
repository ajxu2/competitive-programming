// created: 02-12-2022 Sat 10:43 PM

#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve(1e6+1, true);

void solve() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> a(e); // array with indices each mod residue
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        a[i % e].push_back(tmp);
    }
    // longest chain of 1s that ends at this index
    vector<vector<int>> pre(e);
    for (int i = 0; i < e; i++) {
        pre[i] = vector<int>(a[i].size());
        pre[i][0] = 0;
        for (int j = 1; j < a[i].size(); j++) {
            if (a[i][j-1] == 1) pre[i][j] = pre[i][j-1] + 1;
            else pre[i][j] = 0;
        }
    }
    // longest chain of 1s that starts at this index
    vector<vector<int>> suf(e);
    for (int i = 0; i < e; i++) {
        suf[i] = vector<int>(a[i].size());
        suf[i].back() = 0;
        for (int j = a[i].size()-2; j >= 0; j--) {
            if (a[i][j+1] == 1) suf[i][j] = suf[i][j+1] + 1;
            else suf[i][j] = 0;
        }
    }
    // get answer
    long long ans = 0;
    for (int i = 0; i < e; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            if (sieve[a[i][j]]) {
                ans += (long long)(pre[i][j]+1) * (suf[i][j]+1);
                ans -= 1; // subtract case where k=0
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    // sieve of Eratosthenes
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i <= 1e6; i++) {
        if (!sieve[i]) continue;
        for (int j = 2*i; j <= 1e6; j += i) {
            sieve[j] = false;
        }
    }
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}
