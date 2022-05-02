#include <iostream>
#include <algorithm>

using namespace std;

int needs[100];
int applicants[100];

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int n, m;
	cin >> n >> m;
	int p, l;
	for (int i = 0; i < n; i++) {
		cin >> p >> l;
		for (int j = 0; j < p; j++)	cin >> applicants[j];
		if (p < l)	needs[i] = 1;
		else {
			sort(applicants, applicants + p, compare);
			needs[i] = applicants[l - 1];
		}
	}
	sort(needs, needs + n);
	
	int result = n;
	for (int i = 0; i < n; i++) {
		m -= needs[i];
		if (m < 0) {
			result = i;
			break;
		}
	}
	
	cout << result;
	return 0;
}