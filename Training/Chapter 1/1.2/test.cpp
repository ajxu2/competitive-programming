/*
ID: tony.ji1
LANG: C++14
PROG: test
*/

#include <bits/stdc++.h>
using namespace std;

const string name = "test";

int main() {
#ifndef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
#endif
    int a, b;
    cin >> a >> b;
    cout << a+b << "\n";
    return 0;
}

