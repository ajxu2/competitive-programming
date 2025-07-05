// created: 07-04-2025 Fri 05:11 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

V<ll> fwht(V<ll> a) {
    int n = ssize(a); // note n must be pow of two
    if (n == 1)
        return a;
    V<ll> b(begin(a), begin(a) + n / 2);
    V<ll> c(begin(a) + n / 2, end(a));
    b = fwht(b);
    c = fwht(c);
    for (int i = 0; i < n / 2; i++) {
        a[i] = b[i] + c[i];
        a[i + n / 2] = b[i] - c[i];
    }
    return a;
}

V<ll> ifwht(V<ll> a) {
    a = fwht(a);
    for (ll& i : a)
        i /= ssize(a);
    return a;
}

V<ll> xor_convolve(V<ll> a, V<ll> b) {
    a = fwht(a);
    b = fwht(b);
    for (int i = 0; i < ssize(a); i++)
        a[i] *= b[i];
    return ifwht(a);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    V<int> p(n+1, 0);
    for (int i = 1; i <= n; i++)
        p[i] = p[i-1] ^ a[i-1];
    V<ll> freq(1 << 20, 0);
    for (int i : p)
        freq[i]++;
    V<ll> freq_subarrays = xor_convolve(freq, freq);
    freq_subarrays[0] -= n + 1;
    V<int> ans;
    for (int i = 0; i < ssize(freq_subarrays); i++) {
        if (freq_subarrays[i] > 0)
            ans.push_back(i);
    }
    cout << ssize(ans) << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
    return 0;
}
