// 아래의 코드가 정답에 영향을 미친다..
//ios_base::sync_with_stdio(false);
//cin.tie(nullptr);
//cout.tie(nullptr);


#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	int n;

	int result;

	while (t--) {
		cin >> n;

		result = 0;

		while (n >= 5) {
			result += n / 5;
			n /= 5;
		}

		cout << result << "\n";
	}
	return 0;
}