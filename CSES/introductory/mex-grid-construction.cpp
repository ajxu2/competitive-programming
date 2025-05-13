// created: 05-13-2025 Tue 02:03 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // let's do it the bad way because :grin:
    int n; cin >> n;
    V<V<int>> a(n, V<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            V<int> nums;
            for (int k = 0; k < i; k++)
                nums.push_back(a[k][j]);
            for (int k = 0; k < j; k++)
                nums.push_back(a[i][k]);
            sort(begin(nums), end(nums));
            auto it = begin(nums);
            for (;;) {
                while (it != end(nums) && *it != a[i][j])
                    it++;
                if (it == end(nums))
                    break;
                a[i][j]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " \n"[j == n-1];
    return 0;
}
