// sync_with_stdio 와 tie 를 안썼더니 5%에서 시간 초과가 발생함.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, num;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	nth_element(v.begin(), v.begin() + k - 1, v.end());
	cout << v[k - 1];

	return 0;
}