#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> input;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i <= 20; i++)
		v.push_back(0);

	cin >> N >> K;
	string name;
	for (int i = 0; i < N; i++) {
		cin >> name;
		input.push_back(name.size());
	}
	
	long long result = 0;
	for (int i = 0; i < K + 1; i++) 
		v[input[i]]++;

	for (int i = 1; i <= 20; i++) 
		result += (long long)v[i] * (v[i] - 1) / 2;

	for (int i = K + 1; i < N; i++) {
		v[input[i - K - 1]]--;
		result += v[input[i]];
		v[input[i]]++;
	}

	
	cout << result;
	return 0;
}