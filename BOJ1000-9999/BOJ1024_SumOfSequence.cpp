// ���� �ƴ� ���� ����Ʈ�� ���ϴ� ���α׷����� �������.. { 0 1 2 3 .. } �� ���� �� �� �ִ�.

#include <iostream>
using namespace std;

int main() {
	int n, l;
	cin >> n >> l;
	long long sum = l * (l - 1) / 2;
	if (n < sum) 
		cout << -1;
	else {
		long long x = n - sum;
		long long q = x / l;
		while (x % l != 0) {
			l++;
			sum = l * (l - 1) / 2;
			x = n - sum;
			q = x / l;
		}
		if (l > 100)
			cout << -1;
		else {
			if (q < 0)	cout << -1;
			else {
				for (int i = 0; i < l; i++) {
					cout << i + q << " ";
				}
			}
		}
	}
	return 0;
}