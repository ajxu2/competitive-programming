#include <bits/stdc++.h>
using namespace std;

int main() {
	int y = 0, i = 0;
	string s;
	cin >> s;
	for (; i < s.size() && s[i] != 'h'; i++) {}
	if (s[i] == 'h') {
		y++;
	}
	for (; i < s.size() && s[i] != 'e'; i++) {}
	if (s[i] == 'e') {
		y++;
	}
	for (; i < s.size() && s[i] != 'l'; i++) {}
	if (s[i] == 'l') {
		y++;
	}
	i++;
	for (; i < s.size() && s[i] != 'l'; i++) {}
	if (s[i] == 'l') {
		y++;
	}
	for (; i < s.size() && s[i] != 'o'; i++) {}
	if (s[i] == 'o') {
		y++;
	}
	if (y == 5) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}
