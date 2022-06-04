#include <iostream>

using namespace std;

int n;
char matrix[11][11];
int result[11];

void Brute(int index) {
	if (index == 0) {
		for (int i = 1; i <= n; i++)
			cout << result[i] << " ";
		exit(0);
	}

	int start = 0, end = 0, sum;
	char sign;
	bool flag;
	switch (matrix[index][index]) {
	case '+':	start = 1;		end = 10;	break;
	case '-':	start = -10;	end = -1;	break;
	}
	
	for (int i = start; i <= end; i++) {
		flag = true;
		sum = i;
		for (int j = index + 1; j <= n; j++) {
			sum += result[j];
			if (sum > 0)		sign = '+';
			else if (sum < 0)	sign = '-';
			else				sign = '0';

			if (matrix[index][j] != sign) {
				flag = false;
				break;
			}
		}
		if (flag) {
			result[index] = i;
			Brute(index - 1);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = i; j <= n; j++) 
			cin >> matrix[i][j];

	Brute(n);
	return 0;
}