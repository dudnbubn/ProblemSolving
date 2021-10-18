#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

long long a, b;
long long minimum = ~(1 << 31);
void DFS(long long num, long long move) {
	if (num == b) {
		minimum = min(minimum, move);
		return;
	}
	if(num * 2 <= b)
		DFS(num * 2, move + 1);
	if (num * 10 + 1 <= b)
		DFS(num * 10 + 1, move + 1);
}

int main() {
	cin >> a >> b;
	DFS(a, 1);
	if (minimum == ~(1 << 31))
		cout << -1;
	else
		cout << minimum; 
	return 0;
}