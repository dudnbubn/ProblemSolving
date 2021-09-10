// 처음엔 LCM 함수의 파라미터 값을 int로 했는데 line 7 에서 곱하여 long long 변수에 넣어주는 과정에서 문제가 생겼는지
// 틀렸다고 결과가 나왔다. 그냥 다 long long 으로 바꿔버렸더니 정답이 나왔다.

#include <iostream>
using namespace std;

long long LCM(long long a, long long b) {
	long long result = a * b;
	long long n = a % b;
	while (n != 0) {
		a = b;
		b = n;
		n = a % b;
	}
	return result / b;
}

int main() {
	int n;
	long long a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		cout << LCM(a, b) << "\n";
	}
	return 0;
}