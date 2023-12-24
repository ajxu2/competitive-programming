#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<V<bool>> a(n, V<bool>(n, 0));
    for (int i = 0; i < n-1; i++) {
        string s; cin >> s;
        for (int j = 0; j < n-i; j++) a[i][i+j+1] = s[j] == '1';
    }
    V<V<bool>> adj(n, V<bool>(n, 0));
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            adj[j][j+i] = a[j][j+i];
            for (int k = j+1; k < j+i; k++) {
                if (adj[k][j+i]) adj[j][j+i] = adj[j][j+i] ^ a[j][k];
            }
            //if (adj[j][j+i]) cout << j << " " << j+i << "\n";
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j]) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
