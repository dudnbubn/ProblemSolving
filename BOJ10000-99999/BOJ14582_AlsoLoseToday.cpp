// �ܼ��� ������ �����ؼ� ���ϸ� ������ ���´�.
// nȸ �ʿ� �̱�� �ִٰ� nȸ ���� ���� ���� �����δ� �����־ home���� �̱�� �ִ� ������ �ֱ� ������ �����а� �����ȴ�.

#include <iostream>
using namespace std;

int home[10] = { 0, };
int away[10] = { 0, };

int main() {
	for (int i = 1; i < 10; i++)	cin >> home[i];
	for (int i = 1; i < 10; i++)	cin >> away[i];

	bool flag = false;
	for (int i = 1; i < 10; i++) {
		home[i] += home[i - 1];
		if (home[i] > away[i - 1])	flag = true;
		away[i] += away[i - 1];
	}
	
	if (flag)	cout << "Yes";
	else	cout << "No";
	return 0;
}