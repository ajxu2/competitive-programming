// created: 05-29-2025 Thu 04:53 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    V<V<int>> a(n, V<int>(n));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++)
            a[i][j] = s[j] - 'A';
    }
    V<V<V<int>>> pos(k, V<V<int>>(n)); // positions of letters per row
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            pos[a[i][j]][i].push_back(j);
    for (int i = 0; i < k; i++) {
        V<V<bool>> has_pair(n, V<bool>(n, false));
        bool found = false;
        for (int j = 0; j < n; j++) {
            for (int q1 : pos[i][j]) {
                for (int q2 : pos[i][j]) {
                    if (q1 == q2)
                        continue;
                    if (has_pair[q1][q2]) {
                        found = true;
                        goto done;
                    }
                    has_pair[q1][q2] = true;
                }
            }
        }
        done:;
        cout << (found ? "YES" : "NO") << '\n';
    }
    return 0;
}
