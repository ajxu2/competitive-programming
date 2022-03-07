// created: 03-06-2022 Sun 11:13 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef LOCAL
    ifstream cin("moobuzz.in");
    ofstream cout("moobuzz.out");
#endif
    vector<int> a = {1, 2, 4, 7, 8, 11, 13, 14};
    int n; cin >> n;
    cout << (n-1)/8*15+a[(n-1)%8] << "\n";
    return 0;
}
