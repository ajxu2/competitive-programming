/*
ID: tony.ji1
LANG: C++14
PROG: test
*/

#include <bits/stdc++.h>
using namespace std;

const string filename = "test";

int main() {
#ifndef LOCAL
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
#endif
    int a, b;
    cin >> a >> b;
    cout << a+b << "\n";
    return 0;
}

