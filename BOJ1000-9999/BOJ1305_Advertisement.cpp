#include <iostream>

using namespace std;

int N;
int failure[1'000'001];

void set_failure(string str) {
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
			failure[i++] = 0;
		}
	}
}

int main() {
	string str;
	cin >> N >> str;

	set_failure(str);
	cout << str.size() - failure[N - 1];

}