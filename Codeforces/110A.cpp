#include <bits/stdc++.h>
using namespace std;

int main() {
	string n;
	int ln = 0;
	cin >> n;
	for (int i = 0; i < n.size(); i++) {
		if (n[i] == '4' || n[i] == '7') {
			ln++;
		}
	}
	if (ln == 4 || ln == 7) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}
