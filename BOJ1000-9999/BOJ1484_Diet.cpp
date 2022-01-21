#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<long long> num_set;
vector<int> result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	
	long long square;
	for (int i = 1; i <= 50000; i++) {
		square = (long long)i * i;
		if (num_set.find(square - n) != num_set.end()) {
			result.push_back(i);
		}
		num_set.insert(square);
	}
	if (result.empty())	cout << -1;
	else {
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << "\n";
	}

	return 0;
}