// 인덱스가 점프를 하고 해당 날짜에 상담을 할 수 있는지 체크하는게 헷갈려서 생각보다 애를 먹었다.
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int T[16] = { 0, };
int P[16] = { 0, };
int maximum = 0;

void DFS(int date, int sum) {
	if (date > n) {
		maximum = max(sum, maximum);
		return;
	}
	
	for (int i = date; i <= n; i++) {
		int temp = sum;
		if (i + T[i] <= n + 1) {
			temp += P[i];
		}
		DFS(i + T[i], temp);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> T[i] >> P[i];
	DFS(1, 0);
	cout << maximum;
	
	return 0;
}