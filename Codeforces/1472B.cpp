#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> candies(n);
    for (auto& i : candies) {
        cin >> i;
    }
    sort(candies.begin(), candies.end());
    int one = 0, two = 0;
    for (auto& i : candies) {
        if (i == 1) {
            one++;
        } else {
            two++;
        }
    }
    if ((one + 2 * two) % 2 == 1) {
        cout << "NO\n";
    } else if (((one + two) % 2 == 1) && one == 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}

