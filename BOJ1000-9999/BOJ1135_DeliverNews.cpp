#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> children[50];

bool desc(int a, int b) {
	return a > b;
}

int get_delivery_time(int current) {
	int result = 0;
	vector<int> times;
	for (int child : children[current]) 
		times.push_back(get_delivery_time(child));

	sort(times.begin(), times.end(), desc);
	int weight = 1;
	for (int time : times) 
		result = max(result, time + weight++);

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int parent;
	cin >> parent;
	for (int i = 1; i < N; i++) {
		cin >> parent;
		children[parent].push_back(i);
	}

	cout << get_delivery_time(0);
	return 0;
}