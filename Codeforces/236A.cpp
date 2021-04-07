#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int num = 0;
    vector<bool> chars (26, false);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        chars[s[i] - 'a'] = true;
    }
    for (int i = 0; i < 26; i++) {
        if (chars[i]) {
            num++;
        }
    }
    if (num % 2 == 0) {
        cout << "CHAT WITH HER!\n";
    } else {
        cout << "IGNORE HIM!\n";
    }
    return 0;
}
