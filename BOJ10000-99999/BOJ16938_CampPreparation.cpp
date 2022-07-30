#include <iostream>

using namespace std;

int N, L, R, X;
int A[15];
int result;

#define MAX_VALUE 2147483647
#define MIN_VALUE -2147483648

void Brute(int index, int sum, int maximum, int minimum) {
	if (index == N) {
		if (L <= sum && sum <= R && (maximum - minimum) >= X)
			result++;
		return;
	}

	Brute(index + 1, sum + A[index], max(maximum, A[index]), min(minimum, A[index]));
	Brute(index + 1, sum, maximum, minimum);
}

int main() {
	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++)	cin >> A[i];

	Brute(0, 0, MIN_VALUE, MAX_VALUE);
	cout << result;

	return 0;
}