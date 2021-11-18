#include <iostream>
#include <cmath>
using namespace std;

int arr[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	int start = 0, end = n - 1;
	int minimum = (1 << 31) - 1;
	int sum;
	int result_start, result_end;
	while (start < end) {
		sum = arr[start] + arr[end];
		if (abs(sum) < minimum){
			minimum = abs(sum);
			result_start = arr[start];
			result_end = arr[end];
		}
		if (sum < 0)	start++;
		else	end--;
	}
	cout << result_start << " " << result_end;
	return 0;
}