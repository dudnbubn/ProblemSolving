// 전형적인 브루트포스 문제이다.
#include <iostream>
using namespace std;

int k;
int numbers[50];
int answer[50] = { 0, };
bool isUsed[50] = { 0, };

void DFS(int idx, int prev) {
	if (idx == 7) {
		for (int i = 1; i <= 6; i++)
			cout << answer[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = prev + 1; i <= k; i++) {
		if (!isUsed[i]) {
			isUsed[i] = true;
			answer[idx] = numbers[i];
			DFS(idx + 1, i);
			isUsed[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	while (k != 0) {
		answer[0] = 0;
		for (int i = 1; i <= k; i++) {
			cin >> numbers[i];
			isUsed[i] = false;
			answer[i] = 0;
		}
		DFS(1, 0);
		cout << "\n";
		cin >> k;
	}
	return 0;
}