#include <iostream>
#include <deque>
using namespace std;

void solve() {
    int temp, n;
    deque<int> ans;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        ans.push_front(temp);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
