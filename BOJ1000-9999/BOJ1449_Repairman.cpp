// 물이 새는 곳의 위치가 오름차순으로 주어지지 않는다는 것을 인지해야한다.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, l;
bool hole[2001] = { 0, };
vector<int> holes;

int main() {
	cin >> n >> l;
	int input, cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> input;
		hole[input] = true;
		holes.push_back(input);
	}
	sort(holes.begin(), holes.end());
	for (int i = 0; i < n; i++) {
		if (hole[holes[i]]) {
			cnt++;
			for (int j = 0; j < l && hole[i]+j <= 1000; j++) 
				hole[holes[i] + j] = false;
		}
	}
	cout << cnt;
	return 0;
}