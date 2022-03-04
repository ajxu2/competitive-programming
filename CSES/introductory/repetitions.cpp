#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    int ans = 0, temp = 0;
    char c;
    for (int i = 0; i < s.length(); i++) {
        if ((i == 0) || (s[i] == c)) {
            temp++;
        } else {
            temp = 1;
        }
        c = s[i];
        ans = max(ans, temp);
    }
    cout << ans << "\n";
    return 0;
}
