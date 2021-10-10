#include <iostream>
using namespace std;

bool winner[1001];

int main() {
	int n; 
	cin >> n;

	winner[1] = true;
	winner[2] = false;
	winner[3] = true;
	winner[4] = true;

	for (int i = 5; i <= n; i++) {
		if (winner[i - 1] & winner[i - 3] & winner[i - 4])
			winner[i] = false;
		else
			winner[i] = true;
	}
	
	if (winner[n])	cout << "SK";
	else	cout << "CY";
	return 0;
}