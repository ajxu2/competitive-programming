// created: 02-14-2022 Mon 12:37 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum1 = 0, sum2 = 0;
    vector<int> first, second;

    int last;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if (tmp > 0) {
            first.push_back(tmp);
            sum1 += (long long)tmp;

            if (i == n-1) last = 1;
        } else {
            second.push_back(-1*tmp);
            sum2 += -1LL*tmp;

            if (i == n-1) last = 2;
        }
    }
    if (sum1 > sum2) cout << "first\n";
    else if (sum2 > sum1) cout << "second\n";
    else {
        if (first > second) cout << "first\n";
        else if (second > first) cout << "second\n";
        else {
            if (last == 1) cout << "first\n";
            else cout << "second\n";
        }
    }
    return 0;
}
