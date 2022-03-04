// created: 03-03-2022 Fri 12:30 PM
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<long long> a(10001);
    a[1] = 0; a[2] = 6; a[3] = 28; a[4] = 96;
    for (long long i = 5; i <= 10000; i++) {
        a[i] = (i*i*(i*i-1)-(48+(i-4)*40+(i-4)*(i-4)*8))/2;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << "\n";
    return 0;
}
