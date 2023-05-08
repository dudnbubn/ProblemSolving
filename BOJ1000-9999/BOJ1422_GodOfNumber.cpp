#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> numbers;
vector<string> results;

bool compare1(string a, string b) {
	if (a.size() == b.size()) {
		string ab = a + b;
		string ba = b + a;
		return ab > ba;
	}
	else
		return a.size() > b.size();
}

bool compare2(string a, string b) {
	string ab = a + b;
	string ba = b + a;
	return ab > ba;
}

int main() {
	int K, N;
	cin >> K >> N;

	string s;
	for (int i = 0; i < K; i++) {
		cin >> s;
		numbers.push_back(s);
	}

	sort(numbers.begin(), numbers.end(), compare1);
	
	for (int i = 0; i < N - K; i++)	results.push_back(numbers[0]);
	for (int i = 0; i < K; i++)	results.push_back(numbers[i]);

	sort(results.begin(), results.end(), compare2);
	for (string r : results)	cout << r;

	return 0;
}