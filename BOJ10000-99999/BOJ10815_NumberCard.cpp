// 최대 50만 개를 탐색해야 하므로 이분 탐색을 이용하여 해결할 수 있다.
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int card[500000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> card[i];
	sort(card, card + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int guess;
		cin >> guess;
		
		int start = 0;
		int end = n - 1;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (card[mid] >= guess)
				end = mid - 1;
			else
				start = mid + 1;
		}
		if (card[start] == guess)
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}
	return 0;
}