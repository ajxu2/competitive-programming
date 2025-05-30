// created: 05-29-2025 Thu 02:47 PM

#include <bits/stdc++.h>
using namespace std;

using massive = __int128;
template<class T> using V = vector<T>;

string to_string(massive x) {
    // only works for x >= 0 but ignore that
    if (x == 0)
        return "0";
    string res;
    while (x > 0) {
        res.push_back('0' + (x % 10));
        x /= 10;
    }
    reverse(begin(res), end(res));
    return res;
}

ostream& operator<<(ostream& s, massive x) {
    return s << to_string(x);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // can consider x and y separately
    int n; cin >> n;
    V<int> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    auto sum_1d = [&](V<int> a) -> massive {
        sort(begin(a), end(a));
        int n = ssize(a);
        massive ans = 0;
        for (int i = 0; i < n-1; i++) {
            // segment a[i] -- a[i+1] is counted (i+1)*(n-i-1) times
            ans += (massive)(a[i+1] - a[i]) * (i+1) * (n-i-1);
        }
        return ans;
    };
    cout << sum_1d(x) + sum_1d(y) << '\n';
    return 0;
}
