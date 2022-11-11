#include <iostream>

using namespace std;

string minimum[101];

int main() {
	for (int i = 1; i <= 100; i++)	minimum[i] = "";
	minimum[2] = "1";
	minimum[3] = "7";
	minimum[4] = "4";
	minimum[5] = "2";
	minimum[6] = "0";
	minimum[7] = "8";
	minimum[8] = "10";

	string temp, comp;
	for (int i = 9; i <= 100; i++) {
		minimum[i] = minimum[i - 2] + "99";
		for (int j = 2; j <= 7; j++) {
			comp = minimum[i - j] + minimum[j];
			if (comp[0] == '0')
				comp[0] = '6';

			if (minimum[i].size() > comp.size())
				minimum[i] = comp;
			else if (minimum[i].size() == comp.size()) 
				minimum[i] = minimum[i] < comp ? minimum[i] : comp;
		}
	}

	int TC;
	cin >> TC;

	int N;
	for (int tc = 1; tc <= TC; tc++) {
		cin >> N;
		if (N == 6)	cout << "6 ";
		else	cout << minimum[N] << " ";

		string maximum = "";
		if (N % 2) {
			maximum = "7";
			N -= 3;
		}
		while (N) {
			maximum = maximum + "1";
			N -= 2;
		}
		cout << maximum << "\n";
	}
	return 0;
}