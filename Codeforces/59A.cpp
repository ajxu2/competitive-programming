#include <bits/stdc++.h>
using namespace std;

int main() {
	int lower = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			lower++;
		}
	}
	if (lower >= (s.size()+1)/2) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				s[i] = (char)(s[i] - 'A' + 'a');
			}
		}
	} else {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				s[i] = (char)(s[i] - 'a' + 'A');
			}
		}
	}
	cout << s << "\n";
	return 0;
}
