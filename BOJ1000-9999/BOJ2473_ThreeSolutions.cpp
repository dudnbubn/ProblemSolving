#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long solutions[5000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)	cin >> solutions[i];
	sort(solutions, solutions + N);

	long long minimum = 3'000'000'001;
	long long sum;

	int results[3];
	int index;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			index = lower_bound(solutions + j + 1, solutions + N, (solutions[i] + solutions[j]) * (-1)) - solutions;
			if (index == N)	index--;
			sum = solutions[i] + solutions[j] + solutions[index];
			if (sum < 0)	sum *= -1;
			if (sum < minimum) {
				minimum = sum;
				results[0] = solutions[i];
				results[1] = solutions[j];
				results[2] = solutions[index];
			}

			if (index > j + 1) {
				sum = solutions[i] + solutions[j] + solutions[index - 1];
				if (sum < 0)	sum *= -1;
				if (sum < minimum) {
					minimum = sum;
					results[0] = solutions[i];
					results[1] = solutions[j];
					results[2] = solutions[index - 1];
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)
		cout << results[i] << " ";

	return 0;
}