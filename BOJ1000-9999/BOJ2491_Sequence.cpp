#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100001];
int len = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	
	int asc = 1, des = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[i - 1]) {
			asc++;
			des = 1;
		}
		else if (arr[i] < arr[i - 1]) {
			des++;
			asc = 1;
		}
		else {
			des++;
			asc++;
		}
		len = max(len, max(asc, des));
	}
	cout << len;
	return 0;
}