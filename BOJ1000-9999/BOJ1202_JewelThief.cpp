#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N, K;
pii MV[300001];
int C[300001];

priority_queue<int, vector<int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)	cin >> MV[i].first >> MV[i].second;
	for (int i = 1; i <= K; i++)	cin >> C[i];
	sort(MV + 1, MV + N + 1);
	sort(C + 1, C + K + 1);

	int index = 1;
	long long result = 0;
	for (int i = 1; i <= K; i++) {
		while (index <= N && MV[index].first <= C[i]) {
			pq.push(MV[index].second);
			index++;
		}
		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}
	cout << result;
	return 0;
}