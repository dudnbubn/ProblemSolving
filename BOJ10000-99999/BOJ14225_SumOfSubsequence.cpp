// �κм����� �� �� �ִ� ������ ���ؼ� �� �κм����� ���� ���� �� �ִ� ����� ǥ���صд�.
// ��� ǥ���� �� 1���� ���� �� �ִ� ������ �Ǵ��ϰ� ���� �� ���� ���� ���.
#include <iostream>
using namespace std;

int n;
bool canMake[2000001] = { 0, };
int s[21];
bool visited[21] = { 0, };

void Brute(int k, int prev, int sum) {
	canMake[sum] = true; 
	if (k == n)
		return;
	for (int i = prev + 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			Brute(k + 1, i, sum + s[i]);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	Brute(0, 0, 0);
	for (int i = 1; i <= 2000001; i++) {
		if (!canMake[i]) {
			cout << i;
			return 0;
		}
	}
	return 0;
}