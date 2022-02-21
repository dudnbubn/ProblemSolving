#include <iostream>

using namespace std;

bool pole[5][8];
int index[5];

int main() {
	string input;
	for (int i = 1; i <= 4; i++) {
		cin >> input;
		index[i] = 0;
		for (int j = 0; j < 8; j++) {
			if (input[j] == '1')	pole[i][j] = true;
			else	pole[i][j] = false;
		}
	}
	
	int k;
	cin >> k;
	int num, dir;
	bool check[5];
	while (k--) {
		for (int i = 1; i <= 4; i++)	check[i] = false;
		cin >> num >> dir;
		check[num] = true;
		for (int i = num - 1; i >= 1; i--) {
			if (pole[i][(index[i] + 2) % 8] == pole[i + 1][(index[i + 1] + 6) % 8])
				break;
			check[i] = true;
		}
		for (int i = num + 1; i <= 4; i++) {
			if (pole[i][(index[i] + 6) % 8] == pole[i - 1][(index[i - 1] + 2) % 8])
				break;
			check[i] = true;
		}
		for (int i = 1; i <= 4; i++) {
			if (check[i]) {
				if ((i + num) % 2 == 1)	index[i] = (index[i] + dir + 8) % 8;
				else index[i] = (index[i] - dir + 8) % 8;
			}
		}
	}
	
	int result = 0;
	for (int i = 1, score = 1; i <= 4; i++, score *= 2) {
		if (pole[i][index[i]])	result += score;
	}
	cout << result;
	return 0;
}