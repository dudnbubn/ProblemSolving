#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v[100001];

int main() {
	cin >> N;

	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v[y].push_back(x);
	}
	for (int i = 1; i <= N; i++)
		sort(v[i].begin(), v[i].end());

	long long result = 0;
	for (int i = 1; i <= N; i++) {
		if (v[i].size() == 1)	continue;
		for (int j = 0; j < v[i].size(); j++) {
			if (j == 0)
				result += v[i][j + 1] - v[i][j];
			else if (j == v[i].size() - 1)
				result += v[i][j] - v[i][j - 1];
			else
				result += min(v[i][j + 1] - v[i][j], v[i][j] - v[i][j - 1]);
		}
	}
	cout << result;

	return 0;
}