//10 test cases

#include <iostream>
#include <fstream>
using namespace std;

int N;
int data[100][3];

int main()
{
	ifstream fin ("blist.in");
	ofstream fout ("blist.out");
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> data[i][0] >> data[i][1] >> data[i][2];
	}

	int high = 0;
	for (int i = 0; i < N; i++) {
		if (data[i][1] > high) {
			high = data[i][1];
		}
	}

	int answer = 0;
	int testnumber = 0;
	for (int i = 1; i <= high; i++) {
		for (int j = 0; j < N; j++) {
			if (data[j][0] == i) {
				testnumber = testnumber + data[j][2];
			}
			if (data[j][1] == i) {
				testnumber = testnumber - data[j][2];
			}
		}
		if (testnumber > answer) {
			answer = testnumber;
		}
	}

	fout << answer;
	return 0;
}
