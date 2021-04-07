#include <bits/stdc++.h>
using namespace std;

int main() {
	string original, correct, vasya;
	cin >> original;
	correct = original;
	for (int i = 0; i < original.size(); i++) {
		correct[i] = original[original.size()-i-1];
	}
	cin >> vasya;
	if (correct == vasya) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}
