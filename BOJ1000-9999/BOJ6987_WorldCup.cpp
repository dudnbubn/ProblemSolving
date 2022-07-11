#include <iostream>

using namespace std;

int score[6][3];
bool result[4];

void recur(int t, int p, int q) {
	if (p == 6) 
		result[t] = true;
	else if (q == 6)
		recur(t, p + 1, p + 2);
	else {
		for (int i = 0; i < 3; i++) {
			score[p][i]--;
			score[q][2 - i]--;
			if (score[p][i] >= 0 && score[q][2 - i] >= 0)
				recur(t, p, q + 1);
			score[p][i]++;
			score[q][2 - i]++;
		}
	}
}

int main() {
	for (int t = 0; t < 4; t++) {
		int sum = 0;

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> score[i][j];
				sum += score[i][j];
			}
		}

		if (sum != 30)	result[t] = false;
		else	recur(t, 0, 1);
	}
	for (int t = 0; t < 4; t++)
		if (result[t])
			cout << "1 ";
		else
			cout << "0 ";
}