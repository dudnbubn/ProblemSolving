#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> vector_tc;
map<int, int> map_factor;
map<int, int>::iterator iter;
bool isPrime[100001];

void Eratos(int n) {
	for (int i = 2; i <= n; i++) isPrime[i] = true;
	for (int i = 2; i * i <= n; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= n; j += i)
				isPrime[j] = false;
		}
	}
}

void Factoring(int n) {
	map_factor.clear();
	int index = n;
	while (n > 1) {
		if (!isPrime[index]) {
			index--;
			continue;
		}
		if (n % index == 0) {
			if (map_factor.find(index) == map_factor.end())
				map_factor[index] = 1;
			else
				map_factor[index]++;
			n /= index;
		}
		else
			index--;
	}
	for (iter = map_factor.begin(); iter != map_factor.end(); iter++)
		cout << iter->first << " " << iter->second << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase, n, maximum = 2;
	cin >> testcase;
	while (testcase--) {
		cin >> n;
		vector_tc.push_back(n);
		maximum = max(maximum, n);
	}
	Eratos(maximum);
	for (int i = 0; i < vector_tc.size(); i++)
		Factoring(vector_tc[i]);

	return 0;
}