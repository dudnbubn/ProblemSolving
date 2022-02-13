#include <iostream>
#include <string>

using namespace std;

#define MAXIMUM 10000000

bool isPrime[MAXIMUM];

void Eratos() {
	for (int i = 2; i < MAXIMUM; i++) {
		isPrime[i] = true;
	}
	
	for (int i = 2; i * i < MAXIMUM; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j < MAXIMUM; j += i)
				isPrime[j] = false;
		}
	}
}

bool isPalindrome(int n) {
	int arr[10];
	int index;
	for (index = 0; n; n /= 10, index++) {
		arr[index] = n % 10;
	}
	index--;
	for (int i = 0; i < index; i++, index--) {
		if (arr[i] != arr[index]) 
			return false;
	}
	return true;
}


int main() {
	int n; 
	cin >> n;
	Eratos();

	for (int i = n;; i++) {
		if (isPrime[i]) {
			if (isPalindrome(i)) {
				cout << i;
				return 0;
			}
		}
	}
	return 0;
}