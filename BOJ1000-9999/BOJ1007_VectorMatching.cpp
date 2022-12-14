#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int sum_x, sum_y;
pair<int, int> positions[21];
bool visited[21];
double result;

double get_vector_length(int dx, int dy) {
	return sqrt(pow(dx, 2) + pow(dy, 2));
}

void comb(int depth, int start, int dx, int dy) {
	if (depth == N/2) {
		int res_x = sum_x - (2 * dx);
		int res_y = sum_y - (2 * dy);
		double vector_length = get_vector_length(res_x, res_y);
		result = result < vector_length ? result : vector_length;
		return;
	}

	for (int i = start; i <= N; i++) {
		comb(depth + 1, i + 1, dx + positions[i].first, dy + positions[i].second);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int TC;
	cin >> TC;
	while (TC--) {
		result = 987654321;
		sum_x = 0, sum_y = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> positions[i].first >> positions[i].second;
			sum_x += positions[i].first;
			sum_y += positions[i].second;
		}
		comb(0, 1, 0, 0);
		cout.precision(6);
		cout << fixed << result << "\n";
	}
	return 0;
}