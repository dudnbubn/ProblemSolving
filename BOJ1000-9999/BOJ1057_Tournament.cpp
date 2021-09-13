// 꼭 지민의 번호가 한수의 번호보다 작은 것이 아님을 유의

#include <iostream>
using namespace std;

int main() {
	int n, a, b, round = 1;
	cin >> n >> a >> b;
	while (true) {
		if (a % 2 == 0 && a == b + 1)	break;
		if (b % 2 == 0 && b == a + 1)	break;
		round++;
		a = (a + 1) / 2;
		b = (b + 1) / 2;
	}
	cout << round;
	return 0;
}