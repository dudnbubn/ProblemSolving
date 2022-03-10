#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<string> v;

void Brute(int k, string oper) {
	if (k == n) {
		v.push_back(oper);
		return;
	}
	Brute(k + 1, oper + " ");
	Brute(k + 1, oper + "+");
	Brute(k + 1, oper + "-");
}

int calc(string oper) {
	int arr[10];
	int index = 0;
	arr[0] = 1;
	for (int i = 0, num = 2; i < n - 1; i++, num++) {
		switch (oper[i]) {
		case ' ':
			if (arr[index] > 0)	arr[index] = arr[index] * 10 + num;
			else arr[index] = arr[index] * 10 - num;
			break;
		case '+':
			index++;
			arr[index] = num;
			break;
		case '-':
			index++;
			arr[index] = (-1) * num;
			break;
		}
	}
	int result = 0;
	for (int i = 0; i <= index; i++) {
		result += arr[i];
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		v.clear();
		cin >> n;
		Brute(1, "");

		string output;
		for (int i = 0; i < v.size(); i++) {
			if (calc(v[i]) == 0) {
				output = "1";
				for (int j = 0, num = 2; j < n - 1; j++, num++) {
					output = output + v[i][j] + (char)('0' + num);
				}
				cout << output << "\n";
			}
		}
		
		cout << "\n";
	}
	return 0;
}