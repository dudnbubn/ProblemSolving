#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int matrix[301][301];
bool visited[301];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int input;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		pq.push({ input, i });
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> matrix[i][j];

	int result = 0;
	pair<int, int> cur;
	int weight, number;
	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();

		weight = cur.first;
		number = cur.second;

		if (visited[number])		continue;

		visited[number] = true;
		result += weight;
		
		for (int i = 1; i <= N; i++) {
			if (matrix[number][i] && !visited[i]) {
				pq.push({ matrix[number][i], i });
			}
		}
	}
	
	cout << result;

	return 0;
}