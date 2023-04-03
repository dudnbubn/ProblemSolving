#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100'000

int arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)	cin >> arr[i];

	unsigned long long start = 0, end = 1'000'000'000'000'000'001 / N;
	unsigned long long mid;

	unsigned long long cnt;
	while (start < end) {
		mid = (start + end) / 2;
		
		cnt = 0;
		for (int i = 0; i < N; i++)
			cnt += mid / arr[i];
		
		if (cnt >= M)	end = mid;
		else	start = mid + 1;
	}
	cout << start;
	return 0;
}
