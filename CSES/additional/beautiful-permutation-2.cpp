// created: 11-15-2025 Sat 06:11 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    // idea: we can just repeat the pattern 1 3 5 2 4 in blocks of 5
    // at the end, we should do the following:
    // 5: 1 3 5 2 4
    // 6: 1 3 5 2 4 6
    // 7: 1 3 5 2 6 4 7
    // 8: 1 3 5 2 6 8 4 7
    // 9: 1 3 5 2 4 7 9 6 8
    V<V<int>> stuff = {
    {1, 3, 5, 2, 4},
    {1, 3, 5, 2, 4, 6},
    {1, 3, 5, 2, 6, 4, 7},
    {1, 3, 5, 2, 6, 8, 4, 7},
    {1, 3, 5, 2, 4, 7, 9, 6, 8}
    };
    if (n == 1) {
        cout << "1\n";
    } else if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
    } else if (n == 4) {
        cout << "2 4 1 3\n";
    } else {
        for (int i = 0; i < n / 5 - 1; i++) {
            for (int j = 0; j < 5; j++) {
                cout << 5 * i + stuff[0][j] << ' ';
            }
        }
        for (int i = 0; i < (n % 5) + 5; i++) {
            cout << 5 * (n / 5 - 1) + stuff[n % 5][i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
