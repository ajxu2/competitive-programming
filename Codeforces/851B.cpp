// created: 01-27-2022 Thu 10:58 AM

#include <bits/stdc++.h>
using namespace std;

int main() {
    array<array<int, 2>, 3> a;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }
    // if they're collinear, there is no solution
    array<int, 2> ratio1 = {a[1][1]-a[0][1], a[1][0]-a[0][0]};
    array<int, 2> ratio2 = {a[2][1]-a[0][1], a[2][0]-a[0][0]};
    int reduce = gcd(ratio1[0], ratio1[1]);
    ratio1[0] /= reduce; ratio1[1] /= reduce;
    reduce = gcd(ratio2[0], ratio2[1]);
    ratio2[0] /= reduce; ratio2[1] /= reduce;
    if (ratio1 == ratio2) {
        cout << "NO\n";
        return 0;
    } else {
        ratio1[0] *= -1; ratio1[1] *= -1;
        // could be same with flipped signs
        if (ratio1 == ratio2) {
            cout << "NO\n";
            return 0;
        }
    }
    // otherwise, the distance from A to B and from B to C has to be equal
    long long dist1 = (long long)(a[1][0]-a[0][0])*(a[1][0]-a[0][0])+(long long)(a[1][1]-a[0][1])*(a[1][1]-a[0][1]);
    long long dist2 = (long long)(a[2][0]-a[1][0])*(a[2][0]-a[1][0])+(long long)(a[2][1]-a[1][1])*(a[2][1]-a[1][1]);
    if (dist1 == dist2) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
