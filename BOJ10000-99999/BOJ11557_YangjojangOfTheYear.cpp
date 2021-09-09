#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase, n, alcohol, maximum;
	string name, max_name;
	cin >> testcase;
	while (testcase--) {
		cin >> n;
		maximum = 0;
		for (int i = 0; i < n; i++) {
			cin >> name >> alcohol;
			if (maximum < alcohol) {
				maximum = alcohol;
				max_name = name;
			}
		}
		cout << max_name << "\n";
	}
	return 0;
}