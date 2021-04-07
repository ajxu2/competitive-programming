#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& i : a) {
            cin >> i;
        }
        sort(a.begin(), a.end());
        if (a.back()-k > a.front()+k) {
            cout << "-1\n";
        } else {
            cout << a.front()+k << "\n";
        }
    }
    return 0;
}
