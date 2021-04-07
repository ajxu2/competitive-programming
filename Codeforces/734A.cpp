#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, anton = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') {
			anton++;
		}
	}
	if (anton > n - anton) {
		cout << "Anton\n";
	} else if (anton < n - anton) {
		cout << "Danik\n";
	} else {
		cout << "Friendship\n";
	}
	return 0;
}
