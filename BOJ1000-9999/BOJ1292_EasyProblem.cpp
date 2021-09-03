#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a, b, answer = 0;
	vector<int> v;
	cin >> a >> b;
	for (int i = 1; i <= 50; i++) {
		for (int j = 0; j < i; j++) {
			v.push_back(i);
			if (v.size() >= a)
				answer += i;
			if (v.size() == b) {
				cout << answer;
				return 0;
			}
		}
	}
	return 0;
}