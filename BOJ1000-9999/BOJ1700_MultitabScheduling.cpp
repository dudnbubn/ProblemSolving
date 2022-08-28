#include <iostream>

using namespace std;

int N, K;
int multitab[101];
int ready[101];
bool isUsed[101];

int main() {
	cin >> N >> K;
	for (int i = 1; i <= K; i++)	cin >> ready[i];

	int result = 0, index = 0;
	for (int i = 1; i <= K; i++) {
		if (isUsed[ready[i]])	continue;
		if (index < N) {
			multitab[index++] = ready[i];
			isUsed[ready[i]] = true;
			continue;
		}
		
		result++;
		for (int j = i + 1, temp = N; j < K && temp > 1; j++) {
			if (isUsed[ready[j]]) {
				isUsed[ready[j]] = false;
				temp--;
			}
		}
		for (int j = 0; j < N; j++) {
			if (isUsed[multitab[j]]) {
				isUsed[multitab[j]] = false;
				multitab[j] = ready[i];
				break;
			}
		}
		for (int j = 0; j < N; j++)
			isUsed[multitab[j]] = true;
	}

	cout << result;
	return 0;
}