#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	cout << min(N / 2, M / 2);
	return 0;
}