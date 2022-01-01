#include <iostream>
using namespace std;

bool winner[1001];

int main() {
	winner[1] = false;
	winner[2] = true;
	winner[3] = false;
	winner[4] = true;
	winner[5] = true;
	
	int n;
	cin >> n;
	for (int i = 6; i <= n; i++) {
		if (!winner[i - 1] || !winner[i - 3] || !winner[i - 4])
			winner[i] = true;
		else
			winner[i] = false;
	}
	
	if (winner[n])	cout << "SK";
	else	cout << "CY";
	
	return 0;
}