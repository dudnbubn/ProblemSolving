#include <iostream>
using namespace std;

int main() {
	int origin[6] = { 1,1,2,2,2,8 };
	for (int i = 0; i < 6; i++) {
		int x;
		cin >> x;
		origin[i] -= x;
	}
	for (int i = 0; i < 6; i++)
		cout << origin[i] << " ";
	return 0;
}