#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;

void Brute(int prev, long long num) {
	v.push_back(num);
	for (int i = 0; i < prev; i++)
		Brute(i, num * 10 + i);
}

int main() {
	int n;
	cin >> n;
	v.push_back(0);
	for (int i = 1; i < 10; i++)	Brute(i, i);
	sort(v.begin(), v.end());
	
	if (n < v.size())	cout << v[n];
	else	cout << -1;
	
	return 0;
}