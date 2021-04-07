#include <iostream>
using namespace std;

int main() {
	int t, length, num, filledPerm;
	bool yn;
	cin >> t;
	int permutations[t][50];
	int lengths[t];
	for (int i = 0; i < t; i++) {
		filledPerm = 0;
		cin >> length;
		lengths[i] = length;
		for (int j = 0; j < 2 * length; j++) {
			yn = true;
			cin >> num;
			for (int k = 0; k < filledPerm; k++) {
				if (permutations[i][k] == num) {
					yn = false;
					break;
				}
			}
			if (yn) {
				permutations[i][filledPerm] = num;
				filledPerm++;
			}
		}
	}
	for (int l = 0; l < t; l++) {
		for (int m = 0; m < lengths[l]; m++) {
			cout << permutations[l][m] << " ";
		}
		cout << "\n";
	}
	return 0;
}
