#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long n, sum = 0, temp;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> temp;
        sum += temp;
    }
    cout << (n*(n+1))/2 - sum << "\n";
    return 0;
}
