#include <iostream>
#include <algorithm>

using namespace std;

int M, N;
int L[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >> N;

	int start = 1, end = 0;
	for (int i = 0; i < N; i++) {
		cin >> L[i];
		end = max(end, L[i]);
	}
	sort(L, L + N);

	while (start <= end) {
		int mid = (start + end) / 2;
		int cnt = 0;
		for (int i = 0; i < N; i++)
			cnt += L[i] / mid;

		if (cnt >= M) start = mid + 1;
		else	end = mid - 1;
	}
	cout << end;

	return 0;
}