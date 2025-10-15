// created: 05-29-2025 Thu 04:53 PM
 
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
template<class T> using V = vector<T>;
 
const int MAXN = 3000;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    V<V<int>> a(n, V<int>(n));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++)
            a[i][j] = s[j] - 'A';
    }
    bitset<MAXN * MAXN> has_pair;
    for (int i = 0; i < k; i++) {
        has_pair.reset();
        bool found = false;
        for (int row = 0; row < n; row++) {
            V<int> pos;
            for (int col = 0; col < n; col++)
                if (a[row][col] == i)
                    pos.push_back(col);
            for (int idx1 = 0; idx1 < ssize(pos); idx1++) {
                for (int idx2 = idx1 + 1; idx2 < ssize(pos); idx2++) {
                    int q1 = pos[idx1], q2 = pos[idx2];
                    int idx = q1 * n + q2;
                    if (has_pair[idx]) {
                        found = true;
                        goto done;
                    }
                    has_pair[idx] = true;
                }
            }
        }
        done:;
        cout << (found ? "YES" : "NO") << '\n';
    }
    return 0;
}
