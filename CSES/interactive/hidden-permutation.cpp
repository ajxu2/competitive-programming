// created: 06-29-2025 Sun 12:04 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

bool qry(int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    string s; cin >> s;
    return s == "YES";
}

V<int> mergesort(V<int> a) {
    if (ssize(a) <= 1)
        return a;
    int half = ssize(a) / 2;
    V<int> a1(begin(a), begin(a) + half);
    V<int> a2(begin(a) + half, end(a));
    a1 = mergesort(a1);
    a2 = mergesort(a2);
    V<int> res(ssize(a));
    merge(begin(a1), end(a1), begin(a2), end(a2), begin(res), qry);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> b(n);
    iota(begin(b), end(b), 1);
    b = mergesort(b);
    V<int> a(n);
    for (int i = 0; i < n; i++)
        a[b[i] - 1] = i + 1;
    cout << "! ";
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
