// created: 07-03-2025 Thu 02:04 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

string qry(string s) {
    cout << "? " << s << endl;
    string res; cin >> res;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // just go bit by bit lol
    int n; cin >> n;
    V<int> a(n, 0);
    for (int i = 0; i < 10; i++) {
        string s(n, '0');
        for (int j = 0; j < n; j++) {
            if ((j >> i) & 1)
                s[j] = '1';
        }
        string t = qry(s);
        for (int j = 0; j < n; j++)
            a[j] += (t[j] - '0') << i;
    }
    cout << "! ";
    for (int i : a)
        cout << i + 1 << ' ';
    cout << endl;
    return 0;
}
