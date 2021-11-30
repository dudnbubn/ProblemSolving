// b만큼의 제곱수를 구할 때 b가 홀수라면 b/2를 2번 곱하고 a를 한번 더 곱한 뒤 c로 나눈 나머지
// b가 짝수라면 b/2를 2번 곱한 수를 c로 나눈 나머지
// ex) b = 9 -> pow(b/2) * pow(b/2) * a % c = (a^4 * a^4 * a) % c = a^9 % c
//		, b = 8 -> pow(b/2) * pow(b/2) % c = (a^4 * a^4) % c = a^8 % c

#include <iostream>
using namespace std;

long long a, b, c;

long long pow(int b) {
	if (b == 0)	return 1;

	long long temp = pow(b / 2);
	temp = (temp * temp) % c;
	if (b % 2 == 0)	return temp;
	return (a * temp) % c;
}

int main() {
	cin >> a >> b >> c;
	cout << pow(b);
	
	return 0;
}