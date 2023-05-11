#include <iostream>
#include <vector>

using namespace std;

vector<int> get_prime_factors(int N) {
	vector<int> result;
	int temp_N = N;
	for (int i = 2; i * i <= N; i++) {
		if (temp_N % i == 0) {
			result.push_back(i);
			while (temp_N % i == 0)
				temp_N /= i;
		}
	}
	if (temp_N != 1)
		result.push_back(temp_N);
	return result;
}

int get_euler_phi(int N) {
	int result = N;
	vector<int> prime_factors = get_prime_factors(N);

	for (int prime_factor : prime_factors) 
		result = result * (prime_factor - 1) / prime_factor;
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	while (N) {
		if (N == 1)	cout << "0\n";
		else	cout << get_euler_phi(N) << "\n";
		cin >> N;
	}

	return 0;
}