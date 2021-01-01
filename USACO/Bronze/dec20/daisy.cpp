#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> petals(n);
    for (int i = 0; i < n; i++) {
        cin >> petals[i];
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int sum = 0;
            for (int k = j; k <= i; k++) {
                sum += petals[k];
            }
            if (sum % (i-j+1) == 0) {
                for (int k = j; k <= i; k++) {
                    if (petals[k] == (sum/(i-j+1))) {
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
