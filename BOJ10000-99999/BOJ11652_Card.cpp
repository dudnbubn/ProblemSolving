// 체크해야 할 숫자의 범위가 너무 커서 배열로 만들기는 무리인 것 같다.
// 그래서 map 을 이용했더니 바로 해결되었다.
#include <iostream>
#include <map>
using namespace std;

int n;
map<long long, int> m;
map<long long, int>::iterator iter;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		if (m.find(x) == m.end()) {
			m[x] = 1;
		}
		else
			m[x]++;
	}
	int maximum = 0;
	long long answer = 0;
	for (iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second > maximum) {
			maximum = iter->second;
			answer = iter->first;
		}
	}
	cout << answer;
	return 0;
}