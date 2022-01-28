#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

pair<double, double> arr[101];
bool status[101];
double dist[101];

int main() {
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)	cin >> arr[i].first >> arr[i].second;

	status[1] = true;
	for (int i = 2; i <= n; i++) {
		dist[i] = sqrt((arr[i].first - arr[1].first) * (arr[i].first - arr[1].first) + (arr[i].second - arr[1].second) * (arr[i].second - arr[1].second));
	}
	
	double result = 0;
	double minimum;
	int index = 0;
	for (int k = 2; k <= n; k++) {
		minimum = 1000000000;
		for (int i = 2; i <= n; i++) {
			if (status[i])	continue;
			if (minimum > dist[i]) {
				minimum = dist[i];
				index = i;
			}
		}
		status[index] = true;
		result += minimum;
		for (int i = 2; i <= n; i++) {
			if (status[i])	continue;
			dist[i] = min(dist[i], sqrt((arr[i].first - arr[index].first) * (arr[i].first - arr[index].first) + (arr[i].second - arr[index].second) * (arr[i].second - arr[index].second)));
		}
	}
	cout.precision(2);
	cout << fixed << result;
	return 0;
}