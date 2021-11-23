// created: 08-28-2021 Sat 12:12 AM
 
#include <bits/stdc++.h>
using namespace std;
 
array<int, 2> twosum(vector<array<int, 2>>& orig, int lbound, int rbound, int x) {
    int n = rbound - lbound + 1;
    vector<array<int, 2>> a(n);
    for (int i = lbound; i <= rbound; i++) {
        a[i-lbound][0] = orig[i][0];
        a[i-lbound][1] = orig[i][1];
    }
    int r = n-1;
    for (int l = 0; l < n; l++) {
        while (l != r) {
            if (a[l][0] + a[r][0] == x) {
                return {a[l][1], a[r][1]};
            }
            if (a[l][0] + a[r][0] > x) {
                r--;
            } else {
                break;
            }
        }
        if (l == r) {
            break;
        }
    }
    return {-1, -1};
}
 
int main() {
    int n, x;
    cin >> n >> x;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i+1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n-2; i++) {
        array<int, 2> result = twosum(a, i+1, n-1, x-a[i][0]);
        array<int, 2> noresult = {-1, -1};
        if (result != noresult) {
            cout << a[i][1] << " " << result[0] << " " << result[1] << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
