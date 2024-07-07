// created: 07-06-2024 Sat 08:53 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

double P(int v1, int v2, double t) {
    if (v2 < v1) return 1.;
    return exp((v1 - v2) / t);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    srand(time(NULL)); // cry about it
    int n; cin >> n;
    V<V<int>> coins(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) if (s[j] == 'o') coins[i].push_back(j);
    }
    V<bool> state(n, true); // rows that are active
    V<bool> best = state;
    int curval = n, bestval = n;
    V<int> freq(n, 0);
    // SIMULATED ANNEALING WOOOOOOOOOOOOOOOOOOOOO
    double temp = 1e5;
    for (int i = 0; i < (int)2e6; i++) {
        if (curval < bestval) {
            bestval = curval;
            best = state;
        }
        int idx = rand() % n;
        // flip state[idx]
        int nxtval = curval;
        if (state[idx]) {
            nxtval--;
            for (int j : coins[idx]) if (freq[j] == 0) nxtval++;
        } else {
            nxtval++;
            for (int j : coins[idx]) if (freq[j] == 1) nxtval--;
        }
        if (rand() < P(curval, nxtval, temp) * RAND_MAX) {
            state[idx] = !state[idx];
            for (int j : coins[idx]) {
                if (state[idx]) freq[j]--;
                else freq[j]++;
            }
            curval = nxtval;
        }
        temp *= 0.99999;
    }
    freq.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (!best[i]) for (int j : coins[i]) freq[j]++;
    }
    cout << bestval << '\n';
    for (int i = 0; i < n; i++) {
        if (best[i]) cout << "1 " << i+1 << '\n';
        if (freq[i] > 0) cout << "2 " << i+1 << '\n';
    }
    return 0;
}
