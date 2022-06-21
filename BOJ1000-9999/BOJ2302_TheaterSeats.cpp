#include <iostream>

using namespace std;

int N, M;
int fibo[41];

int main() {
	cin >> N;
	fibo[0] = 1;	fibo[1] = 1;
	for (int i = 2; i <= N; i++)	fibo[i] = fibo[i - 1] + fibo[i - 2];

	cin >> M;
	int result = 1;
	int vip, prev = 1;
	for (int i = 0; i < M; i++) {
		cin >> vip;
		result *= fibo[vip - prev];
		prev = vip + 1;
	}
	result *= fibo[N + 1 - prev];

	cout << result;
	
	return 0;
}