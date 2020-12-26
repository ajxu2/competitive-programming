#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> order[i];
    }
    int ptr = n-1;
    while (order[ptr] - order[ptr-1] > 0 && ptr > 0) {
        ptr--;
    }
    cout << ptr << "\n";
    return 0;
}
