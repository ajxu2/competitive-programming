// created: 05-16-2026 Sat 07:03 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

// cp algorithms SMILE
const int K = 26;

struct Vertex {
    int next[K];
    bool output = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].output = true;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}

const int MOD = 998'244'353;

V<V<ll>> operator*(const V<V<ll>>& a, const V<V<ll>>& b) {
    // assume a = n * p, b = p * m
    int n = ssize(a), p = ssize(a[0]), m = ssize(b[0]);
    V<V<ll>> res(n, V<ll>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                (res[i][j] += a[i][k] * b[k][j]) %= MOD;
            }
        }
    }
    return res;
}

V<V<ll>>& operator*=(V<V<ll>>& a, const V<V<ll>>& b) { return a = a * b; }

V<V<ll>> pow(V<V<ll>> a, ll b) {
    // only for square matrices
    int n = ssize(a);
    V<V<ll>> res(n, V<ll>(n, 0));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a; b >>= 1;
    }
    return res;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    V<string> a(k);
    for (string& i : a)
        cin >> i;
    for (string i : a)
        add_string(i);
    int m = ssize(t);
    for (int i = 0; i < m; i++)
        for (int j = get_link(i); j != 0; j = get_link(j))
            t[i].output |= t[j].output;
    V<V<ll>> adj(m + 1, V<ll>(m + 1, 0));
    for (int u = 0; u < m; u++) {
        for (int ch = 0; ch < 26; ch++) {
            int nxt = go(u, 'a' + ch);
            if (t[nxt].output)
                adj[u][m]++;
            else
                adj[u][nxt]++;
        }
    }
    V<V<ll>> res = pow(adj, n);
    ll ans = 0;
    for (int u = 0; u < m; u++)
        (ans += res[0][u]) %= MOD;
    cout << ans << '\n';
    return 0;
}
