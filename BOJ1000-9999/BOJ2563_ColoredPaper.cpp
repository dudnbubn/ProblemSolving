// 처음엔 총 색종이의 넓이에서 겹치는 부분을 빼주는 방법으로 풀었더니 틀린 답이 나왔다..
// 이미 빼준 부분에 대해 또 빼준 것이 문제였다. ex) input : 3 0 0 1 1 2 2
// 결국 (0, 0) ~ (99, 99) 까지 칠해진 부분을 체크하여 총 개수를 구하는 방법으로 풀었다.

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