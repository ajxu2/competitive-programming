#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, ans = 0, temp, people = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		people -= temp;
		cin >> temp;
		people += temp;
		ans = max(ans, people);
	}
	cout << ans << "\n";
	return 0;
}
