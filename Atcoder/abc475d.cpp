// created: 09-12-2026 Sat 09:14 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

bool is_prime(int n) {
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if ((n & 1) == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = ssize(s);
    V<char> ordering;
    for (int i = n - 1; i >= 0; i--) {
        if (find(begin(ordering), end(ordering), s[i]) != end(ordering))
            continue;
        ordering.push_back(s[i]);
    }
    int m = ssize(ordering);
    V<bool> used(10, false);
    V<int> digits;
    auto get_digit = [&](char c) -> int {
        for (int i = 0; i < m; i++)
            if (ordering[i] == c)
                return digits[i];
        return 0;
    };
    int ans = -1;
    auto backtrack = [&](this auto self, int i) -> void {
        if (i == m) {
            string t(n, 0);
            for (int j = 0; j < n; j++)
                t[j] = '0' + get_digit(s[j]);
            if (t[0] == '0')
                return;
            int t_int = stoi(t);
            if (ans == -1 && is_prime(t_int))
                ans = t_int;
            return;
        }
        for (int nxt = 0; nxt < 10; nxt++) {
            if (!used[nxt]) {
                used[nxt] = true;
                digits.push_back(nxt);
                self(i + 1);
                digits.pop_back();
                used[nxt] = false;
            }
        }
    };
    backtrack(0);
    cout << ans << '\n';
    return 0;
}
