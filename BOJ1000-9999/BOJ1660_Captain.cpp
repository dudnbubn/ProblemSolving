// 사이즈가 i인 사면체를 만들기 위한 대포알의 수가 a[i] 이고
// j개의 대포알을 가지고 만들 수 있는 사면체의 갯수를 cnt[j]에 저장한다.
// n = 40이라고 할 때,
//	a[1] = 1 에 대해 cnt[40] = 40 이다.
//	a[2] = 4 에 대해서는 cnt[40]과 cnt[40 - a[2]] 를 비교한다. 
//	즉, a[2] 사면체를 사용하기 전의 갯수 cnt[36]에 1을 더한 것에 대해 비교하여 작은 값을 채택한다. (36개를 통해 만든 사면체 갯수에 a[2]로 만든 사면체 하나를 더하면 되므로)
//	따라서 a[2]에 대해서 cnt[4] = min(4, cnt[4 - a[2]] + 1) = min(4, 1) -> cnt[4] = 1	이 때 min의 첫 번째 인자는 a[1]을 통해 만들어지는 사면체의 갯수
//	cnt[8] = min(8, cnt[8 - a[2]] + 1) = min(8, cnt[4] + 1) = min(8, 2) -> cnt[8] = 2
//	...
//	cnt[40] = min(40, cnt[40 - a[2]] + 1) = min(8, cnt[36] + 1) min(40, 10) -> cnt[40] = 10

//	위 과정을 a[i] <= n 일 때 까지 계속 진행한다.
// 자세한 값은 line 34에서 확인할 수 있다.

#include <iostream>
#include <algorithm>
using namespace std;

int a[800] = { 0, };
int cnt[300001] = { 0, };

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < 800; i++)
		a[i] = a[i - 1] + i;
	for (int i = 1; i < 121; i++)
		a[i] += a[i - 1];

	for (int i = 0; i <= n; i++)	cnt[i] = i;
	for (int i = 2; i < 121; i++) {
		for (int j = a[i]; j <= n; j++) {
			//cout << "cnt[" << j << "] = min(cnt[" << j << "], cnt[" << j << " - a[" << i << "]] + 1) = min(" << cnt[j] << ", " << cnt[j - a[i]] + 1<< ")\n";
			cnt[j] = min(cnt[j], (cnt[j - a[i]] + 1));
		}
	}
	cout << cnt[n];
	return 0;
}