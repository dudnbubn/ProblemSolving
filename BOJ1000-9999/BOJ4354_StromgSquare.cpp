#include <iostream>

using namespace std;

string str;
int failure[1000000];

void get_failure() {
	int i = 1, j = 0;
	failure[0] = 0;

	int str_size = str.size();

	while (i < str_size) {
		if (str[i] == str[j]) {
			failure[i++] = ++j;
		}
		else if (j > 0) {
			j = failure[j - 1];
		}
		else {
			failure[i] = 0;
			i++;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> str;
	while (str != ".") {
		get_failure();

		int str_size = str.size();
		int div = str_size - failure[str_size - 1];

		if (str_size % div)
			cout << 1 << "\n";
		else
			cout << str_size / div << "\n";

		cin >> str;
	}
}