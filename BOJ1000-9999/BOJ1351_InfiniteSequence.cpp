#include <iostream>
#include <map>
using namespace std;

int p, q;
map<long long, long long> dp_map;

long long recur(long long n) {
	if (n == 0)	return 1;
	
	if (dp_map.find(n) != dp_map.end())	return dp_map[n];
	else	return dp_map[n] = recur(n / p) + recur(n / q);
}

int main() {
	long long n;
	cin >> n >> p >> q;
	cout << recur(n);
	return 0;
}