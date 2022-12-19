#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string.h>

using namespace std;

int N;
vector<pair<int, int>> arr;
int cache[100000];
int bound[100000];

int LIS() {
	int index = 0;
	cache[0] = arr[0].second;
	
	for (int i = 1; i < N; i++) {
		if (cache[index] < arr[i].second) {
			cache[++index] = arr[i].second;
			bound[i] = index;
		}
		else {
			int index2 = lower_bound(cache, cache + index, arr[i].second) - cache;
			bound[i] = index2;
			cache[index2] = arr[i].second;
		}
	}
	return index + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		arr.push_back({ a, b });
	}
	sort(arr.begin(), arr.end());
	
	stack<int> result;
	int lis = LIS();

	int index = lis - 1;
	for (int i = N - 1; i >= 0; i--) {
		if (bound[i] == index) 
			index--;
		else
			result.push(arr[i].first);
	}

	cout << N - lis << "\n";
	while (!result.empty()) {
		cout << result.top() << "\n";
		result.pop();
	}
	return 0;
}