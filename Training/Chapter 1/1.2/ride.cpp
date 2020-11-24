/*
ID: tony.ji1
LANG: C++14
PROG: ride
*/

#include <bits/stdc++.h>
using namespace std;

const string name = "ride";

int main() {
#ifndef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
#endif
    string a, b;
    int aProd = 1, bProd = 1;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        aProd *= (a[i] - 'A' + 1);
    }
    for (int i = 0; i < b.size(); i++) {
        bProd *= (b[i] - 'A' + 1);
    }
    if ((aProd % 47) == (bProd % 47)) {
        cout << "GO\n";
    } else {
        cout << "STAY\n";
    }
    return 0;
}

