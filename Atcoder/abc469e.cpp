// created: 08-01-2026 Sat 09:03 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const double EPS = 1e-9;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    V<int> os;
    for (int i = 0; i < n; i++)
        if (s[i] == 'o')
            os.push_back(i);
    // binary search (on floats??!!)
    double l = 0, r = 1;
    while (r - l > EPS) {
        double mid = midpoint(l, r);
        // average >= mid = average >= 0 when shifted = sum >= 0
        V<double> p(n + 1, 0);
        for (int i = 1; i <= n; i++)
            p[i] = p[i - 1] + (s[i - 1] == 'o' ? 1 - mid : -mid);
        V<double> min_p(n + 1, 0);
        for (int i = 1; i <= n; i++)
            min_p[i] = min(min_p[i - 1], p[i]);
        bool good = false;
        for (int i = k - 1; i < ssize(os); i++)
            if (p[os[i] + 1] - min_p[os[i - k + 1]] >= 0)
                good = true;
        if (!good)
            r = mid;
        else
            l = mid;
    }
    cout << fixed << setprecision(10) << l << '\n';
    return 0;
}
