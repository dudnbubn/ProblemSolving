// ó���� LCM �Լ��� �Ķ���� ���� int�� �ߴµ� line 7 ���� ���Ͽ� long long ������ �־��ִ� �������� ������ �������
// Ʋ�ȴٰ� ����� ���Դ�. �׳� �� long long ���� �ٲ���ȴ��� ������ ���Դ�.

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