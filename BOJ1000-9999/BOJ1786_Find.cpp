	#include <iostream>
#include <string>
#include <vector>

using namespace std;

int f[1000001];
vector<int> result;

void failure(string P) {
	int i = 1, j = 0;
	while (i < P.size()) {
		if (P[i] == P[j]) 
			f[i] = ++j;
		else if (j > 0) 
			j = f[j - 1];
		else
			i++;
	}
}

void kmp(string T, string P) {
	int i = 0, j = 0;
	while (i < T.size()) {
		if (T[i] == P[j]) {
			if (j == P.size() - 1) {
				result.push_back(i - P.size() + 2);
				i++;
				j = f[j];
			}
			else {
				i++;
				j++;
			}
		}
		else if (j > 0)
			j = f[j - 1];
		else
			i++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string T, P;
	getline(cin, T);
	getline(cin, P);
	
	failure(P);
	kmp(T, P);

	cout << result.size() << "\n";
	for (int i : result)
		cout << i << " ";

	return 0;
}