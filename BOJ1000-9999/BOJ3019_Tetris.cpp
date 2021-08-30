// 각 블럭에 대해 회전하는 모양을 고려하여 열을 한 바퀴 돌면서 카운트하면 해결되는 노가다성 문제이다...
#include <iostream>
using namespace std;

int c, p;
int state[101] = { 0, };

int caseCount(int block) {
	int cnt = 0;
	if (block == 1) {
		for (int i = 1; i <= c - 3; i++)
			if ((state[i] == state[i + 1]) && (state[i + 1] == state[i + 2]) && (state[i + 2] == state[i + 3]))
				cnt++;
		cnt += c;
	}
	else if (block == 2) {
		for (int i = 1; i <= c - 1; i++)
			if(state[i] == state[i+1])
				cnt++;
	}
	else if (block == 3) {
		for (int i = c; i >= 2; i--) {
			if (state[i] == state[i - 1] - 1)
				cnt++;
			if ((i != 2) && (state[i] == state[i - 1] + 1) && (state[i - 1] == state[i - 2]))
				cnt++;
		}
	}
	else if (block == 4) {
		for (int i = c; i >= 2; i--) {
			if (state[i] == state[i - 1] + 1)
				cnt++;
			if ((i != 2) && (state[i - 2] == state[i - 1] + 1) && (state[i - 1] == state[i]))
				cnt++;
		}
	}
	else if (block == 5) {
		for (int i = 1; i <= c; i++) {
			if (i != 1 && i != c) {
				if ((state[i - 1] == state[i]) && (state[i] == state[i + 1]))
					cnt++;
				if ((state[i - 1] == state[i] + 1) && (state[i] + 1 == state[i + 1]))
					cnt++;
			}
			if (i != c && state[i] == state[i + 1] - 1)
				cnt++;
			if (i != 1 && state[i] == state[i - 1] - 1)
				cnt++;
		}
	}
	else if (block == 6) {
		for (int i = 1; i <= c - 2; i++) {
			if (state[i] == state[i + 1]) {
				cnt++;
				if (state[i + 1] == state[i + 2])
					cnt++;
			}
			if (state[i] == state[i + 1] + 2)
				cnt++;
			if ((state[i] == state[i + 1] - 1) && (state[i + 1] == state[i + 2]))
				cnt++;
		}
		if (state[c] == state[c - 1])
			cnt++;
		if (state[c] == state[c - 1] - 2)
			cnt++;
	}
	else if (block == 7) {
		for (int i = 1; i <= c - 2; i++) {
			if (state[i] == state[i + 1]) {
				cnt++;
				if (state[i + 1] == state[i + 2])
					cnt++;
			}
			if (state[i] == state[i + 1] - 2)
				cnt++;
			if ((state[i] == state[i + 1]) && (state[i + 1] == state[i + 2] + 1))
				cnt++;
		}
		if (state[c] == state[c - 1])
			cnt++;
		if (state[c] == state[c - 1] + 2)
			cnt++;
	}
	return cnt;
}

int main() {
	cin >> c >> p;
	for (int i = 1; i <= c; i++)
		cin >> state[i];

	cout << caseCount(p);
	return 0;
}