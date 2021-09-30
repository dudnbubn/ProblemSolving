#include <iostream>
#include <algorithm>
using namespace std;

int arr[50001];

int main() {
	int n, cnt = 0;
	cin >> n;
	bool flag_i = false, flag_j = false, flag_k = false, flag_l = false;
	for (int i = 1; i <= n; i++)	arr[i] = i;
	for (int i = 0; i * i <= n; i++) {
		for (int j = i; i * i + j * j <= n; j++) {
			for (int k = j; i * i + j * j + k * k <= n; k++) {
				for (int l = k; i * i + j * j + k * k + l * l <= n; l++) {
					cnt = 0;
					if (flag_i)	cnt++;
					if (flag_j)	cnt++;
					if (flag_k)	cnt++;
					if (flag_l)	cnt++;
					arr[i * i + j * j + k * k + l * l] = min(cnt, arr[i * i + j * j + k * k + l * l]);
					
					flag_l = true;
				}
				flag_k = true;
			}
			flag_j = true;
		}
		flag_i = true;
	}
	cout << arr[n];
	return 0;
}