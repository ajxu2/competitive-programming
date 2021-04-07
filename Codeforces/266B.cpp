#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t;
	string s, ns;
	char swap;
	cin >> n >> t >> s;
	for (int i = 0; i < t; i++) {
		ns = s;
		for (int j = 0; j < n-1; j++) {
			if (s[j] == 'B' && s[j+1] == 'G') {
				swap = ns[j];
				ns[j] = ns[j+1];
				ns[j+1] = swap;
			}
		}
		s = ns;
	}
	cout << s << "\n";
	return 0;
}
