// created: 08-28-2024 Wed 07:03 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = ssize(s);
    // z-algorithm
    V<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) {
            l = i; r = i + z[i];
        }
    }
    // KMP
    V<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && pi[i] == 0) {
            j = pi[j - 1];
            if (s[j] == s[i]) pi[i] = j + 1;
        }
    }
    for (int i = 0; i < n; i++) cout << z[i] << " \n"[i == n-1];
    for (int i = 0; i < n; i++) cout << pi[i] << " \n"[i == n-1];
    return 0;
}
