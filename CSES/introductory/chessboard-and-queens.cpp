// created: 03-03-2022 Fri 3:00 PM
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    vector<vector<bool>> a(8, vector<bool>(8));
    for (int i = 0; i < 8; i++) {
        string s; cin >> s;
        for (int j = 0; j < 8; j++) a[i][j] = (s[j] == '*');
    }
    vector<int> tmp = {0,1,2,3,4,5,6,7};
    int ans = 0;
    do {
        bool works = true;
        // check not reserved
        for (int i = 0; i < 8; i++) if (a[i][tmp[i]]) works = false;
        // check not attacking
        for (int i = 0; i < 8; i++) {
            for (int j = i+1; j < 8; j++) {
                if (i-j == tmp[i]-tmp[j] || i-j == tmp[j]-tmp[i]) works = false;
            }
        }
        if (works) ans++;
    } while (next_permutation(tmp.begin(), tmp.end()));
    cout << ans << "\n";
    return 0;
}
