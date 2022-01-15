#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int arr[100000];
int result = 987654321;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	sort(arr, arr + n);

	int start = 0;
	int end = n - 1;
	int sum;
	int save_start, save_end;
	while (start < end) {
		sum = arr[start] + arr[end];
		if (result > abs(sum)) {
			result = abs(sum);
			save_start = arr[start];
			save_end = arr[end];
		}
		if (sum == 0)	break;
		else if (sum > 0)	end--;
		else	start++;
	}
	cout << save_start << " " << save_end;
	return 0;
}