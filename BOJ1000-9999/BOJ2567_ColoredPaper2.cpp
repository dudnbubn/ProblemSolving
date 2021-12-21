#include <iostream>
using namespace std;

bool colored[100][100] = { 0, };
int d_x[4] = { 0,-1,0,1 };
int d_y[4] = { -1,0,1,0 };

int main() {
	int n;
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;

		for (int dx = 0; dx < 10; dx++) 
			for (int dy = 0; dy < 10; dy++) 
				colored[x + dx][y + dy] = true;
	}
	
	int len = 0;
	int next_x, next_y;
	for (x = 0; x < 100; x++) {
		for (y = 0; y < 100; y++) {
			if (colored[x][y]) {
				for (int k = 0; k < 4; k++) {
					next_x = x + d_x[k];
					next_y = y + d_y[k];
					if (next_x < 0 || next_y < 0 || next_x >= 100 || next_y >= 100 || !colored[next_x][next_y])
						len++;
				}
			}
		}
	}
	cout << len;
	return 0;
}