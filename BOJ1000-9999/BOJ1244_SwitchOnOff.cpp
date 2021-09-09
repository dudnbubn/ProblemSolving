#include <iostream>
using namespace std;

bool swit[101] = { 0, };
int n, student, gender, num;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> swit[i];
	cin >> student;
	for (int i = 0; i < student; i++) {
		cin >> gender >> num;
		if (gender == 1) {
			for (int j = 1; j * num <= n; j++)
				swit[j * num] = !swit[j * num];
		}
		else {
			for (int j = 0; num - j > 0 && num + j <= n; j++) {
				if (swit[num - j] != swit[num + j])	break;
				swit[num - j] = !swit[num - j];
				swit[num + j] = swit[num - j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << (int)swit[i] << " ";
		if (i % 20 == 0)	cout << "\n";
	}
	return 0;
}