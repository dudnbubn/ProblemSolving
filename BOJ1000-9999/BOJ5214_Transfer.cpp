#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, K, M;
vector<int> linked[100001];
vector<int> hyper[1000];
int result[100001];

queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K >> M;
	for (int i = 0; i <= N; i++)	result[i] = 1e9;
	int input;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> input;
			hyper[i].push_back(input);
			linked[input].push_back(i);
		}
	}
	
	
	q.push(1);
	result[1] = 1;
	int cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (int tube : linked[cur]) {
			for (int t : hyper[tube]) {
				if (result[cur] + 1 < result[t]) {
					result[t] = result[cur] + 1;
					q.push(t);
				}
			}
		}
	}
	
	if (result[N] == 1e9)	cout << -1;
	else	cout << result[N];

	return 0;
}