#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, num, ans = 0;
    cin >> t;
    vector<vector<int> > arr;
    arr.resize(t);
    for (int i = 0; i < t; i++) {
        arr[i].resize(3);
    }
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < t; i++) {
        num = 0;
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == 1) {
                num++;
            }
        }
        if (num >= 2) {
            ans++;
        }
    }
    cout << ans << "\n";
}
