#include <iostream>
#include <algorithm>

using namespace std;

string arr[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	int n;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)	cin >> arr[i];
		sort(arr, arr + n);
		
		bool flag = false;

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				flag = false;
				for (int k = 0; k < arr[i].size(); k++) {
					if (arr[i][k] != arr[j][k]) {
						flag = true;
						break;
					}
				}
				if (!flag)	break;
			}
			if (!flag)	break;
		}
		if (flag)	cout << "YES\n";
		else	cout << "NO\n";
	}
	return 0;
}