#include <iostream>

using namespace std;

int main() {
	string input;
	cin >> input;
	int input_size;
	bool is_palindrome;
	while (input != "0") {
		input_size = input.size();
		is_palindrome = true;
		for (int i = 0; i < input_size; i++) {
			if (input[i] != input[input_size - i - 1]) {
				is_palindrome = false;
				break;
			}
		}
		cout << (is_palindrome ? "yes\n" : "no\n");
		cin >> input;
	}
	return 0;
}