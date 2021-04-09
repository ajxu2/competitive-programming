// created: 04-09-2021 Fri 12:08 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string answer(s);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            answer[s.length()-(i/2+1)] = s[s.length()-(i+1)];
        } else {
            answer[(i-1)/2] = s[s.length()-(i+1)];
        }
    }
    cout << answer << "\n";
    return 0;
}
