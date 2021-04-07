#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		char l = s[i];
		if (l == 'H' || l == 'Q' || l == '9') {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
