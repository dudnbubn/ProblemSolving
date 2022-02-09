#include <iostream>

using namespace std;

int n;

void recur(int cur, int dir, bool outline) {
	string str = "";
	
	if (outline) {
		for (int i = 0; i < 4 * n - 3; i++) 
			str = str + '*';
		int cnt = n - cur;
		int left = 1, right = 4 * n - 5;
		while (cnt--) {
			str[left] = ' ';
			str[right] = ' ';
			left += 2;
			right -= 2;
		}
	}
	else {
		for (int i = 0; i < 4 * n - 3; i++)
			str = str + " ";
		int cnt = n - cur + 1;
		int left = 0, right = 4 * n - 4;
		while (cnt--) {
			str[left] = '*';
			str[right] = '*';
			left += 2;
			right -= 2;
		}
	}
	cout << str << "\n";
	
	if (cur == 1) 
		dir = 1;

	if (cur == n && dir == 1 && outline)
		return;

	if (dir == -1) {
		if (outline)	recur(cur, dir, !outline);
		else	recur(cur + dir, dir, !outline);
	}
	else {
		if (outline)	recur(cur + dir, dir, !outline);
		else	recur(cur, dir, !outline);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	recur(n, -1, true);
	return 0;
}