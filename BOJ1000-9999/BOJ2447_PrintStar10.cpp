#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	bool flag;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			flag = true;
			for (int k = 3; k <= N; k *= 3) {
				int start = k / 3, end = (k / 3) * 2 + 1;
				if ((start < (i % k) && (i % k) < end) && (start < (j % k) && (j % k) < end)) {
					flag = false;
					break;
				}
			}
			if (flag)	cout << '*';
			else	cout << ' ';
			
		}
		cout << "\n";
	}

	return 0;
}