#include <iostream>
#include <algorithm>
using namespace std;

int n, m, total = 0;
int arr[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		total += arr[i];
	}
	sort(arr, arr + n);
	cin >> m;
	if (total <= m)	cout << arr[n - 1];
	else {
		int dif = total - m;
		int cut = 0;
		int index = n - 1;
		while (cut < dif) {
			cut += (arr[index] - arr[index - 1]) * (n - index);
			arr[index] = arr[index - 1];
			index--;
		}
		index++;
		cut -= dif;
		cut /= (n - index);
		cout << arr[index] + cut;
	}
	return 0;
}