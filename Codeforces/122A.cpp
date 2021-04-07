#include <bits/stdc++.h>
using namespace std;

int main() {
	int lucky[14] = {
		4, 7,
		44, 47, 74, 77,
		444, 447, 474, 477, 744, 747, 774, 777
	};
	int n;
	cin >> n;
	for (int i = 0; i < 14; i++) {
		if (n % lucky[i] == 0) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
