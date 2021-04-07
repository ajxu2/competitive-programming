#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int cLength;
	char num;
	string s;
	cin >> s;
	num = s[0];
	cLength = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == num) {
			cLength++;
		} else {
			num = s[i];
			cLength = 1;
		}
		if (cLength == 7) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
 
