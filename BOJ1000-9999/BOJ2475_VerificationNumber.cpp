#include <iostream>
using namespace std;

int main() {
	int answer = 0;
	int num;
	for (int i = 0; i < 5; i++) {
		cin >> num;
		answer += (num * num);
	}
	cout << answer % 10;
	return 0;
}