#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> cows[100];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> cows[i].first >> cows[i].second;
	sort(cows, cows + n);
	
	int result = 0;
	for (int i = 0; i < n; i++) 
		result = max(result, cows[i].first) + cows[i].second;

	cout << result;
	return 0;
}