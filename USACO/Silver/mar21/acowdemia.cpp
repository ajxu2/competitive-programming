// created: 01-02-2022 Sun 08:26 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    // sort in reverse
    sort(c.begin(), c.end(), greater<int>());
    // idea: binary search on h-index
    // min h-index is 0, max is n
    int h, left = 0, right = n;
    while (left < right) {
        h = (left+right+1)/2;
        // how much we need to add to each number to get h
        vector<int> toAdd(n);
        for (int i = 0; i < n; i++) {
            if (c[i] >= h) toAdd[i] = 0;
            else toAdd[i] = h - c[i];
        }
        long long cites = 0;
        bool works = true;
        for (int i = 0; i < h; i++) {
            if (toAdd[i] > k) {
                // can't cite a paper more than k times
                works = false;
                break;
            }
            cites += toAdd[i];
        }
        // can't have too many citations
        if (cites > (long long)k*l) works = false;
        if (works) {
            left = h;
        } else {
            right = h - 1;
        }
    }
    cout << left << "\n";
    return 0;
}
