// ó���� �� �������� ���̿��� ��ġ�� �κ��� ���ִ� ������� Ǯ������ Ʋ�� ���� ���Դ�..
// �̹� ���� �κп� ���� �� ���� ���� ��������. ex) input : 3 0 0 1 1 2 2
// �ᱹ (0, 0) ~ (99, 99) ���� ĥ���� �κ��� üũ�Ͽ� �� ������ ���ϴ� ������� Ǯ����.

#include <iostream>
using namespace std;

bool paper[111][111] = { 0, };

int main() {
	int n, r, c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> r >> c;
		for (int j = r; j < r + 10; j++) {
			for (int k = c; k < c + 10; k++)
				paper[j][k] = true;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (paper[i][j])	cnt++;
		}
	}
	cout << cnt;
	return 0;
}