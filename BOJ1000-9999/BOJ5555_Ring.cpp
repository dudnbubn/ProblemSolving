#include <iostream>
#include <string>
using namespace std;

string want;
int n;
string rings[101];

int main() {
	cin >> want;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> rings[i];
		rings[i] = rings[i] + rings[i];

		for (int j = 0; j <= 10; j++) {
			if (rings[i].substr(j, want.size()) == want) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}