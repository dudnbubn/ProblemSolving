#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 2'147'483'647

int K, N;
int prime_numbers[100];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> prime_pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> K >> N;
	for (int k = 0; k < K; k++) 
		cin >> prime_numbers[k];

	sort(prime_numbers, prime_numbers + K);
	for (int k = 0; k < K; k++)
		prime_pq.push({ prime_numbers[k], k });


	pair<int, int> current;
	long long minimum, multiple;
	int index;
	while (N--) {
		current = prime_pq.top();
		prime_pq.pop();

		minimum = current.first;
		index = current.second;

		for (int k = index; k < K; k++) {
			multiple = minimum * prime_numbers[k];
			if (multiple >= INF)	continue;
			prime_pq.push({ multiple, k });
		}
	}
	cout << minimum;
	return 0;
}