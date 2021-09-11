#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase, n, w, b;
	string start, end;
	cin >> testcase;
	while (testcase--) {
		w = 0;	b = 0;
		cin >> n;
		cin >> start >> end;
		for (int i = 0; i < n; i++) {
			if (start[i] != end[i]) {
				if (start[i] == 'W')	w++;
				else	b++;
			}
		}
		cout << max(w, b) << "\n";
	}
	return 0;
}