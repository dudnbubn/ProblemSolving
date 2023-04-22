#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define MAX_VALUE 200

int N;
int arr[MAX_N + 1][MAX_N + 1];

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };
int is_visited[MAX_N + 1][MAX_N + 1][MAX_VALUE + 1];

typedef pair<pair<int, int>, pair<int, int>> Info;
queue<Info> q;

bool move_to_endpoint(int gap) {
	q = {};
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			for (int k = 0; k <= MAX_VALUE; k++)
				is_visited[i][j][k] = MAX_VALUE + 1;

	is_visited[1][1][0] = true;
	q.push({ { 1, 1 }, { arr[1][1], arr[1][1] } });
	Info current;
	int ci, cj, minimum, maximum;
	int ni, nj, next_minimum, next_maximum;
	while (!q.empty()) {
		current = q.front();
		q.pop();

		ci = current.first.first;
		cj = current.first.second;
		minimum = current.second.first;
		maximum = current.second.second;

		if (ci == N && cj == N)	return true;

		for (int d = 0; d < 4; d++) {
			ni = ci + di[d];
			nj = cj + dj[d];
			
			if (ni < 1 || nj < 1 || ni > N || nj > N)	continue;

			next_minimum = minimum < arr[ni][nj] ? minimum : arr[ni][nj];
			next_maximum = maximum > arr[ni][nj] ? maximum : arr[ni][nj];

			if (next_maximum - next_minimum > gap || is_visited[ni][nj][next_minimum] <= next_maximum - next_minimum)	continue;

			is_visited[ni][nj][next_minimum] = next_maximum - next_minimum;

			q.push({ {ni, nj}, {next_minimum, next_maximum} });
		}
	}
	
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	int start = 0, end = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			end = end > arr[i][j] ? end : arr[i][j];
		}
	}

	int mid;
	while (start < end) {
		mid = (start + end) / 2;

		bool can_move = move_to_endpoint(mid);
		if (can_move) end = mid;
		else	start = mid + 1;
	}

	cout << end;
	return 0;
}