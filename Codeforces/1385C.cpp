#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, current, prog, swap;
    vector<int> arr;
    vector<int> diffs;
    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        diffs.resize(n-1);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n-1; i++) {
            if (arr[i+1] - arr[i] > 0) {
                diffs[i] = 1;
            } else if (arr[i+1] - arr[i] < 0) {
                diffs[i] = -1;
            } else {
                diffs[i] = 0;
            }
        }
        current = -1;
        prog = n-2;
        while (prog >= 0 && (diffs[prog] == current || diffs[prog] == 0)) {
            prog--;
        }
        current = diffs[prog];
        while (prog >= 0 && (diffs[prog] == current || diffs[prog] == 0)) {
            prog--;
        }
        cout << prog+1 << "\n";
    }
    return 0;
}
