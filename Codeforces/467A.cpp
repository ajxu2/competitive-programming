#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	vector<pair<int, int> > people;
	cin >> n;
	people.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> people[i].first >> people[i].second;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (people[i].second - people[i].first >= 2) {
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}
