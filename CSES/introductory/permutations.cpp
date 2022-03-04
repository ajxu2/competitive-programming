#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    if (n == 1) {
        cout << "1\n";
    } else if (n <= 3) {
        cout << "NO SOLUTION\n";
    } else {
        if (n % 2 == 0) {
            for (int i = 0; i < n; i += 2) {
                a[i] = (i/2)+1;
                a[i+1] = n - a[i] + 1;
            }
        } else {
            for (int i = 0; i < n-1; i += 2) {
                a[i] = (i/2)+1;
                a[i+1] = n - a[i] + 1;
            }
            a[n-1] = (n+1)/2;
        }
        cout << a[n-1] << " ";
        for (int i = 0; i < n-1; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
