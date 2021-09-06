#include <iostream>
using namespace std;

int main() {
	string answer = "";
	int a, b, n, q;
	cin >> a >> b >> n;
	while (answer.size() <= n) {
		q = a / b;
		a = a % b;
		answer += (char)q;
		a *= 10;
	}
	cout << (int)answer[n];
	return 0;
}