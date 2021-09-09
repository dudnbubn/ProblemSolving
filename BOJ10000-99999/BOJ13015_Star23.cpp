#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string s;
	cin >> n;
	for (int i = 0; i < 2 * n - 1; i++) {
		s = "";
		if (i == 0 || i == 2 * n - 2) {
			for (int j = 0; j < n; j++)	s = s + '*';
			for (int j = 0; j < 2 * n - 3; j++)	s = s + ' ';
			for (int j = 0; j < n; j++)	s = s + '*';
		}
		else if (i == n - 1) {
			for (int j = 0; j < n - 1; j++)	s = s + ' ';
			s = s + '*';
			for (int j = 0; j < n - 2; j++)	s = s + ' ';
			s = s + '*';
			for (int j = 0; j < n - 2; j++)	s = s + ' ';
			s = s + '*';
		}
		else {
			int temp;
			if (i < n - 1)	temp = i;
			else	temp = 2 * (n - 1) - i;
			for (int j = 0; j < temp; j++)	s = s + ' ';
			s = s + '*';
			for (int j = 0; j < n - 2; j++)	s = s + ' ';
			s = s + '*';
			for (int j = 0; j < 2 * (n - temp - 2) + 1; j++) s = s + ' ';
			s = s + '*';
			for (int j = 0; j < n - 2; j++)	s = s + ' ';
			s = s + '*';
		}
		cout << s << "\n";
	}
}