#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	bool works;
	vector<int> arr;
	vector<int> diffs;
	cin >> n;
	arr.resize(n);
	works = true;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	for (int i = 1; i < n; i++) {
		if (arr[i] - arr[i-1] > 1) {
			works = false;
			break;
		}
	}
	if (works) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
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
 
