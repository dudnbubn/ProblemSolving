#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<string> list;

bool compare(string a, string b) {
	if (a.size() == b.size()) {
		int sum_a = 0, sum_b = 0;
		for (int i = 0; i < a.size(); i++)
			if ('0' <= a[i] && a[i] <= '9')
				sum_a += (a[i] - '0');
		for (int i = 0; i < b.size(); i++)
			if ('0' <= b[i] && b[i] <= '9')
				sum_b += (b[i] - '0');
		if (sum_a == sum_b)	return a < b;
		return sum_a < sum_b;
	}
	return a.size() < b.size();
}

int main() {
	cin >> n;
	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		list.push_back(input);
	}
	sort(list.begin(), list.end(), compare);
	for (string s : list)
		cout << s << "\n";
	return 0;

}