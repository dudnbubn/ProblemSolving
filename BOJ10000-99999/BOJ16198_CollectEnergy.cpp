// 브루트포스를 이용하는 문제.
// 파라미터로 벡터를 받는 것과 구슬 하나를 제거 할 때마다 벡터를 복사하는 것이 조금 신경쓰였는데 다행히 문제가 되진 않았다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> w;
int maximum = 0;

void Brute(vector<int> v, int e) {
	if (v.size() == 2) {
		maximum = max(maximum, e);
		return;
	}
	vector<int> temp;
	for (int i = 1; i < v.size() - 1; i++) {
		temp = v;
		temp.erase(temp.begin() + i);
		Brute(temp, e + (temp[i - 1] * temp[i]));
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		w.push_back(x);
	}
	Brute(w, 0);
	cout << maximum;
	return 0;
}