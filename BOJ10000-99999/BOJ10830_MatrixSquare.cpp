#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n;
map<long long, vector<vector<int>>> m;
vector<vector<int>> a;

vector<vector<int>> recur(long long b) {
	if (m.find(b) != m.end())	return m[b];
	if (b == 1)	return a;
	long long half = b / 2;
	
	vector<vector<int>> temp_a = recur(half);
	vector<vector<int>> temp_b = recur(b - half);
	vector<vector<int>> result;
	long long value;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		result.push_back(temp);
		for (int j = 0; j < n; j++) {
			value = 0;
			for (int k = 0; k < n; k++) {
				value = (value + ((long long)temp_a[i][k] * temp_b[k][j]) % 1000) % 1000;
			}
			result[i].push_back(value);
		}
	}
	return m[b] = result;
}

int main() {
	long long b;
	cin >> n >> b;
	
	int x;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		a.push_back(temp);
		for (int j = 0; j < n; j++) {
			cin >> x;
			x %= 1000;
			a[i].push_back(x);
		}
	}

	vector<vector<int>> result = recur(b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << result[i][j] << " ";
		cout << "\n";
	}
	return 0;
}