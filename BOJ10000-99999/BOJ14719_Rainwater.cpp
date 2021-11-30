// �� ���̿� ���Ͽ� ���� ���̵��� ���ʿ� ���� �ִ��� �Ǵ��Ͽ�
// ���ʿ� ���� �����ϸ� ���� �ο��ִ� ĭ �� ��ŭ ������� ���Ѵ�.

#include <iostream>
using namespace std;

int blocks[500];

int main() {
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < w; i++)	cin >> blocks[i];

	int result = 0, open;
	bool hole;
	for (int i = 1; i <= h; i++) {
		open = -1;	hole = false;
		for (int j = 0; j < w; j++) {
			if (blocks[j] >= i) {
				if (!hole)
					open = j;
				else {
					result += (j - open - 1);
					open = j;
					hole = false;
				}
			}
			else {
				if (open != -1)
					hole = true;
			}
		}
	}
	cout << result;
	return 0;
}