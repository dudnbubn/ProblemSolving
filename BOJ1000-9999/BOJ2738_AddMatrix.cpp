#include <iostream>

using namespace std;

int N, M, i, j, k;
int a[100][100];

int main() {
	cin >> N >> M;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cin >> a[i][j];

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> k;
			cout << a[i][j] + k << " ";
		}
		cout << "\n";
	}
}