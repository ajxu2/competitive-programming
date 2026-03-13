// created: 03-02-2026 Mon 08:16 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    V<int> pos_a, pos_b, pos_c;
    for (int i = 0; i < ssize(s); i++) {
        if (s[i] == 'A')
            pos_a.push_back(i);
        else if (s[i] == 'B')
            pos_b.push_back(i);
        else
            pos_c.push_back(i);
    }
    int ptr_a = 0, ptr_b = 0, ptr_c = 0;
    while (ptr_a < ssize(pos_a)) {
        while (ptr_b < ssize(pos_b) && pos_b[ptr_b] < pos_a[ptr_a])
            ptr_b++;
        if (ptr_b == ssize(pos_b)) {
            cout << ptr_a << '\n';
            return 0;
        }
        while (ptr_c < ssize(pos_c) && pos_c[ptr_c] < pos_b[ptr_b])
            ptr_c++;
        if (ptr_c == ssize(pos_c)) {
            cout << ptr_a << '\n';
            return 0;
        }
        ptr_a++; ptr_b++; ptr_c++;
    }
    cout << ptr_a << '\n';
    return 0;
}
