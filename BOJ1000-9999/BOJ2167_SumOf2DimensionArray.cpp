#include <iostream>

using namespace std;

int arr[301][301];
int subsum[301][301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			subsum[i][j] = subsum[i - 1][j] + subsum[i][j - 1] - subsum[i - 1][j - 1] + arr[i][j];
		}
	}

	int K;
	cin >> K;
	int a, b, c, d;
	for (int k = 0; k < K; k++) {
		cin >> a >> b >> c >> d;
		cout << subsum[c][d] - subsum[a - 1][d] - subsum[c][b - 1] + subsum[a - 1][b - 1] << "\n";
	}
	return 0;
}