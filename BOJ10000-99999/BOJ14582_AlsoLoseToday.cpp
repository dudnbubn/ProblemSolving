// 단순히 점수를 누적해서 비교하면 오답이 나온다.
// n회 초에 이기고 있다가 n회 말에 지면 누적 점수로는 지고있어도 home팀이 이기고 있는 순간이 있기 때문에 역전패가 성립된다.

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