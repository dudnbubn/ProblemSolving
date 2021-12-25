#include <iostream>
#include <algorithm>
using namespace std;

int x, y;
int n;
pair<int, int> store[100];
int d[100];

int main() {
	cin >> x >> y;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> store[i].first >> store[i].second;
	int result = 0;
	int dir, dist;
	cin >> dir >> dist;
	int temp;
	for (int i = 0; i < n; i++) {
		if (dir == 1) {
			switch (store[i].first) {
			case 1:	temp = abs(dist - store[i].second);	break;
			case 2:	temp = (min(dist + store[i].second, 2 * x - (dist + store[i].second)) + y); break;
			case 3:	temp = (store[i].second + dist);	break;
			case 4:	temp = (x - dist + store[i].second);	break;
			}
		}
		else if (dir == 2) {
			switch (store[i].first) {
			case 1:	temp = (min(dist + store[i].second, 2 * x - (dist + store[i].second)) + y);	break;
			case 2:	temp = abs(dist - store[i].second); break;
			case 3:	temp = (y - store[i].second + dist);	break;
			case 4:	temp = (x - dist + y - store[i].second);	break;
			}
		}
		else if (dir == 3) {
			switch (store[i].first) {
			case 1:	temp = (store[i].second + dist);	break;
			case 2:	temp = (y - dist + store[i].second); break;
			case 3:	temp = abs(dist - store[i].second);	break;
			case 4:	temp = (min(dist + store[i].second, 2 * y - (dist + store[i].second)) + x);	break;
			}
		}
		else {
			switch (store[i].first) {
			case 1:	temp = (dist + x - store[i].second);	break;
			case 2:	temp = (y - dist + x - store[i].second); break;
			case 3:	temp = (min(dist + store[i].second, 2 * y - (dist + store[i].second)) + x);	break;
			case 4:	temp = abs(dist - store[i].second);	break;
			}
		}
		result += temp;
	}
	cout << result;
	return 0;
}