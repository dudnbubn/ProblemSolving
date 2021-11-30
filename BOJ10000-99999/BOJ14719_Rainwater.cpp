// 각 높이에 대하여 물이 고이도록 양쪽에 블럭이 있는지 판단하여
// 양쪽에 블럭이 존재하면 블럭에 싸여있는 칸 수 만큼 결과값에 더한다.

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