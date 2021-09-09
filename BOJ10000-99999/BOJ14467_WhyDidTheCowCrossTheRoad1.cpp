#include <iostream>
using namespace std;

int cows[11];
int n;

int main() {
	for (int i = 1; i <= 10; i++)	cows[i] = -1;
	cin >> n;

	int cow, position, cnt = 0;;
	for (int i = 0; i < n; i++) {
		cin >> cow >> position;
		if (cows[cow] == -1) cows[cow] = position;
		else {
			if (cows[cow] != position) {
				cnt++;
				cows[cow] = position;
			}
		}
	}
	cout << cnt;
	return 0;
}