#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, minCandy, minOrange;
	long long ans = 0;
	vector<vector<int> > data;
	vector<vector<int> > diffs;
	cin >> n;
	data.resize(2);
	data[0].resize(n);
	data[1].resize(n);
	diffs.resize(2);
	diffs[0].resize(n);
	diffs[1].resize(n);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> data[i][j];
		}
	}
	minCandy = data[0][0];
	minOrange = data[1][0];
	for (int i = 1; i < n; i++) {
		if (data[0][i] < minCandy) {
			minCandy = data[0][i];
		}
		if (data[1][i] < minOrange) {
			minOrange = data[1][i];
		}
	}
	for (int i = 0; i < n; i++)  {
		diffs[0][i] = data[0][i] - minCandy;
		diffs[1][i] = data[1][i] - minOrange;
	}
	for (int i = 0; i < n; i++) {
		ans += max(diffs[0][i], diffs[1][i]);
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
 
