#include <iostream>
using namespace std;

int main() {
	int l, p;
	int answer[5];
	cin >> l >> p;
	for (int i = 0; i < 5; i++) {
		cin >> answer[i];
		answer[i] -= (l * p);
	}
	for (int i = 0; i < 5; i++)
		cout << answer[i] << " ";
	return 0;
}