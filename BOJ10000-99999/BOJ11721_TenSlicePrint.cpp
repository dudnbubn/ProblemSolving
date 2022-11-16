#include <iostream>
using namespace std;int main() {string input;cin >> input;for (int i = 1; i <= input.size(); i++) {cout << input[i-1];if (i % 10 == 0)cout << '\n';}}