#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int t;
    cin >> t;
    int best = t, worst = t;
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        cin >> t;
        if (best != max(best, t)) {
            best = max(best, t);
            ans++;
        }
        if (worst != min(worst, t)) {
            worst = min(worst, t);
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
