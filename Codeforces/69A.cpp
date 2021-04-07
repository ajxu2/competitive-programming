#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; 
	vector<vector<int> > forces;
	vector<int> sums(3,0);
	cin >> n;
	forces.resize(n);
	for (int i = 0; i < n; i++) {
		forces[i].resize(3);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> forces[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			sums[i] += forces[j][i];
		}
	}
	if (sums[0] == 0 && sums[1] == 0 && sums[2] == 0) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}
 
