#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_VALUE 360'000
#define MAX_N 200'000

int arr1[MAX_N];
int arr2[MAX_N];

int failure[MAX_VALUE + 1];

void get_failure(vector<int> t) {
	failure[0] = 0;
	int i = 1, j = 0;

	int t_size = t.size();
	while (i < t_size) {
		if (t[i] == t[j])	failure[i++] = ++j;
		else if (j > 0)	j = failure[j - 1];
		else	failure[i++] = 0;
	}
}

bool KMP(vector<int> s, vector<int> t) {
	int i = 0, j = 0;
	int s_size = s.size();
	int t_size = t.size();
	while (i < s.size()) {
		if (s[i] == t[j]) {
			if (j == t_size - 1)	return true;
			i++;
			j++;
		}
		else if (j > 0) {
			j = failure[j - 1];
		}
		else {
			i++;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr1[i];
	for (int i = 0; i < N; i++)	cin >> arr2[i];
	
	sort(arr1, arr1 + N);
	sort(arr2, arr2 + N);

	int gap;
	vector<int> s;
	for (int i = 0; i < N; i++) {
		gap = (arr1[(i + 1) % N] - arr1[i] + MAX_VALUE) % MAX_VALUE;
		s.push_back(gap);
	}
	s.insert(s.end(), s.begin(), s.end());

	vector<int> t;
	for (int i = 0; i < N; i++) {
		gap = (arr2[(i + 1) % N] - arr2[i] + MAX_VALUE) % MAX_VALUE;
		t.push_back(gap);
	}

	get_failure(t);
	bool result = KMP(s, t);

	
	cout << (result ? "possible" : "impossible");
	
	return 0;
}