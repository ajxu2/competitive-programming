#include <bits/stdc++.h>
using namespace std;

long long choosetwo(long long a) {
    if (a < 2) return 0;
    return a*(a-1)/2;
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    long long ans = choosetwo(k);
    vector<int> boys(k);
    for (auto& i : boys) {
        cin >> i;
    }
    sort(boys.begin(), boys.end());
    int repeat = 1;
    for (int i = 0; i < k-1; i++) {
        if (boys[i] == boys[i+1]) {
            repeat++;
        } else {
            ans -= choosetwo(repeat);
            repeat = 1;
        }
    }
    ans -= choosetwo(repeat);
    vector<int> girls(k);
    for (auto& i : girls) {
        cin >> i;
    }
    sort(girls.begin(), girls.end());
    repeat = 1;
    for (int i = 0; i < k-1; i++) {
        if (girls[i] == girls[i+1]) {
            repeat++;
        } else {
            ans -= choosetwo(repeat);
            repeat = 1;
        }
    }
    ans -= choosetwo(repeat);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}
