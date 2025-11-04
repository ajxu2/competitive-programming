// created: 10-25-2025 Sat 08:01 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    int sum = accumulate(begin(a), end(a), 0);
    int needed = sum - m;
    sort(begin(a), end(a));
    if (binary_search(begin(a), end(a), needed))
        cout << "Yes";
    else
        cout << "No";
    cout << '\n';
    return 0;
}
