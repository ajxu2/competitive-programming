// original file lost lol, this is an attempted rewrite of my solution

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin("diamond.in");
    ofstream cout("diamond.out");
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int r = 0;
    vector<int> b(n);
    for (int l = 0; l < n; l++) {
        while (r != n-1) {
            r++;
            if (a[r] - a[l] > k) {
                r--;
                break;
            }
        }
        b[l] = r;
    }
    vector<int> s(n);
    s[n-1] = b[n-1]-(n-1)+1;
    for (int i = n-2; i >= 0; i--) {
        s[i] = max(s[i+1], b[i]-i+1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, b[i]-i+1+s[b[i]+1]);
    }
    cout << ans << "\n";
    return 0;
}