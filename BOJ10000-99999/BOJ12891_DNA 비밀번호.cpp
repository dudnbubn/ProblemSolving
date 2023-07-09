#include <iostream>

using namespace std;

int conditions[4];
int counts[4];

int get_index(char c) {
	switch (c) {
	case 'A':	return 0;
	case 'C':	return 1;
	case 'G':	return 2;
	case 'T':	return 3;
	}
}

bool is_password() {
	for (int i = 0; i < 4; i++) {
		if (counts[i] < conditions[i])	return false;
	}
	return true;
}

int main() {
	int s_size, p_size;
	cin >> s_size >> p_size;
	
	string s;
	cin >> s;

	for (int i = 0; i < 4; i++)	cin >> conditions[i];
	
	int index;
	for (int i = 0; i < p_size; i++) {
		index = get_index(s[i]);
		counts[index]++;
	}

	int result = 0;
	if (is_password())	result++;
	
	for (int i = p_size; i < s_size; i++) {
		index = get_index(s[i]);
		counts[index]++;
		index = get_index(s[i - p_size]);
		counts[index]--;
		if (is_password())	result++;
	}

	cout << result;
	return 0;
}