// created: 03-03-2022 Thu 09:33 PM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long k; cin >> k;
    long long tmp = 9;
    int digits = 1;
    while (true) {
        // subtract 9*1, then 90*2, then 900*3, etc.
        if (k - tmp*digits <= 0) break;
        k -= tmp*digits;
        tmp *= 10;
        digits++;
    }
    // get k-th digit
    k--; // 0 indexing yay
    // get the actual number
    long long num = 1;
    for (int i = 0; i < digits-1; i++) num *= 10;
    num += k/digits;
    k %= digits;
    cout << to_string(num)[k] << "\n"; // ugly
}

int main() {
    int q; cin >> q;
    while (q--) solve(); 
    return 0;
}
