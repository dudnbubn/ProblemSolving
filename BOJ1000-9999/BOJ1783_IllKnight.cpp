// 위, 아래로는 자유롭게 이동하지만 항상 오른쪽으로 적어도 1칸씩 이동
// 세로 길이가 1, 2, 3 이상일 때의 경우와 각 경우에 대한 가로 길이 경우를 따짐
// 예를 들어 세로 길이가 3 이상일 때 위, 아래의 이동은 더이상 의미가 없어지므로 가로 길이에 대해 답이 구해짐

// 시간 제한을 2초나 주길래 각 경우를 이동하면서 따져보는 줄 알았는데 그냥 경우만 따지면 되는 것이었음

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if (n == 1)	cout << 1;
	else if (n == 2) {
		cout << min((m - 1) / 2 + 1, 4);
	}
	else {
		if (m >= 7)
			cout << m - 2;
		else {
			cout << min(4, m);
		}
	}
	return 0;
}