#include <iostream>

using namespace std;

int maximum;
int arr[12][12];
int visited[12];

void Brute(int index, int score) {
	if (index == 12) {
		maximum = (maximum < score ? score : maximum);
		return;
	}

	for (int i = 1; i <= 11; i++) {
		if (arr[index][i] != 0 && !visited[i]) {
			visited[i] = true;
			Brute(index + 1, score + arr[index][i]);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		for (int i = 1; i <= 11; i++) {
			visited[i] = false;
			for (int j = 1; j <= 11; j++) {
				cin >> arr[i][j];
			}
		}
		maximum = 0;
		Brute(1, 0);
		cout << maximum << "\n";
	}
	return 0;
}