/*
 * LCS on Permutations
 *
 * You are given two permutations a and b of length N (1<=N<=1e5). Determine the length of their longest common subsequence.
 *
 * Input
 * Line 1: The single integer N
 * Line 2: A permutation of length N
 * Line 3: Another permutation of length N
 *
 * Output
 * A single integer: the answer to the above problem
 */

// created: 05-25-2022 Wed 07:42 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    // if we relabel the numbers such that the first permutation is 1 2 3 4 5, we can reduce this to a LIS problem!!!
    int n; cin >> n;
    vector<int> rl(n+1);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        rl[a] = i;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = rl[x];
    }
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        if (it == dp.end()) dp.push_back(a[i]);
        else *it = a[i];
    }
    cout << dp.size() << "\n";
    return 0;
}
