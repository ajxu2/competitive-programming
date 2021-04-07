#include <iostream>
#include <string>
using namespace std;

string lower(string s) {
    string ns;
    ns = s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            ns[i] = (char)(s[i] - 'A' + 'a');
        }
    }
    return ns;
}

int main() {
    string a, b;
    cin >> a >> b;
    a = lower(a);
    b = lower(b);
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < b[i]) {
            cout << -1 << "\n";
            return 0;
        }
        if (a[i] > b[i]) {
            cout << 1 << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
    return 0;
}
