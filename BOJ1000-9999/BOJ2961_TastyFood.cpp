#include <iostream>
#include <cmath>

using namespace std;

int n;
int mul[10];
int add[10];
bool visited[10];
int result = 987654321;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> mul[i] >> add[i];

	int end = 1;
	int m, a;
	for (int i = 0; i < n; i++)	end *= 2;
	for (int i = 1; i < end; i++) {
		m = 1;	a = 0;
		for (int j = 1, index = n - 1; j <= i; j *= 2, index--) {
			if (i & j) {
				m *= mul[index];
				a += add[index];
			}
		}
		
		result = min(result, abs(m - a));
	}
	cout << result;
	return 0;
}