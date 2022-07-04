// key point : ������ �׵��
// F[n + m] = F[n - 1] * F[m] + F[n] * F[m + 1]
// �� ������ ��� n > m ���� �������־�� �ذ��̵Ǵ� �� ����.
// ex)	F[3] ���� n = 1, m = 2 (X)	n = 2, m = 1 (O)
//		F[3] = F[1] * F[1] + F[2] * F[2]		

#include <iostream>
#include <unordered_map>

using namespace std;

#define DIV 1000000007

unordered_map<long long, long long> um;

long long fibo(long long k) {
	if (k == 0)	return 0;
	if (k == 1 || k == 2)	return 1;
	if (um.find(k) != um.end())	return um[k];
	


	long long m = k / 2;
	long long n = k - m;

	return um[k] = ((fibo(n - 1) * fibo(m)) % DIV + (fibo(n) * fibo(m + 1)) % DIV) % DIV;
}

int main() {
	long long n;
	cin >> n;

	cout << fibo(n);
	return 0;
}