// created: 02-11-2022 Fri 2:47 PM

#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;
int cnt[200];

void solve() {
    cin >> n >> k >> s;
    fill(cnt, cnt+200, 0);
    for (int i : s) cnt[i]++;
    // get the number of pairs
    int cnt1 = 0;
    for (int i = 'a'; i <= 'z'; i++) cnt1 += cnt[i] / 2;
    // allocate the pairs to the k palindromes
    int ans = cnt1 / k * 2;
    // if >= k characters left, give each palindrome 1 character
    if (n - ans * k >= k) ans++;
    cout << ans << "\n";
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}
