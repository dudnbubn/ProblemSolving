// key point : Binary Search

#include <iostream>
#include <algorithm>

using namespace std;

int N, k;

int main() {
	cin >> N >> k;

	int start = 1, end = k;
	while (start <= end) {
		int mid = (start + end) / 2;

		int cnt = 0;
		for (int i = 1; i <= N; i++)
			cnt += min(mid / i, N);

		if (cnt < k)	start = mid + 1;
		else	end = mid - 1;
	}
	cout << start;
	return 0;
}