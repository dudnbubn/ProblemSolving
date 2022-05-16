#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[i])	continue;
			return a[i] < b[i];
		}
	}
	return a.size() < b.size();
}
int main() {
	int n;
	string input, number;
	vector<string> result;
	bool prevNumber;
	cin >> n;
	for (int i = 0; i < n; i++) {
		prevNumber = false;
		number = "";
		cin >> input;
		for (int j = 0; j < input.size(); j++) {
			if ('0' <= input[j] && input[j] <= '9') {
				if (prevNumber) {
					if (number[0] == '0')	number[0] = input[j];
					else	number = number + input[j];
				}
				else {
					number = input[j];
				}
				prevNumber = true;
			}
			else {
				if (prevNumber) {
					result.push_back(number);
					number = "";
				}
				prevNumber = false;
			}
		}
		if (prevNumber)
			result.push_back(number);
	}
	sort(result.begin(), result.end(), compare);
	for (string s : result)
		cout << s << "\n";
	
	return 0;
}