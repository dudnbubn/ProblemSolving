#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int colors[300000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	int start = 1, end = 0;
	for (int i = 0; i < M; i++) {
		cin >> colors[i];
		end = end > colors[i] ? end : colors[i];
	}

	int cnt, index;
	while (start <= end) {
		int mid = (start + end) / 2;
		cnt = 0;

		for (int i = 0; i < M; i++) {
			if (colors[i] % mid == 0)	cnt += colors[i] / mid;
			else	cnt += colors[i] / mid + 1;
		}

		if (cnt > N)	start = mid + 1;
		else	end = mid - 1;
	}

	cout << start;
	return 0;
}