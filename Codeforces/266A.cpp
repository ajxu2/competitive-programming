#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int cLength = 1, len, ans = 0;
	char let;
	string s;
	cin >> len >> s;
	let = s[0];
	for (int i = 1; i < len; i++) {
		if (s[i] == let)  {
			cLength++;
		} else {
			ans += cLength-1;
			cLength = 1;
			let = s[i];
		}
	}
	ans += cLength-1;
	cout << ans;
	return 0;
}
 
