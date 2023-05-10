#include <iostream>
#include <map>
#include <string>

using namespace std;

map<int, string> to_rome;
map<string, int> to_arabia;

int get_arabia(string rome) {
	string temp = "";
	int result = 0;
	bool flag = true;
	for (int i = 0; i < rome.size() - 1; i++) {
		temp = rome.substr(i, 2);
		if (to_arabia.find(temp) != to_arabia.end()) {
			if (i == rome.size() - 2)
				flag = false;
			result += to_arabia[temp];
			i++;
		}
		else {
			result += to_arabia[rome.substr(i, 1)];
		}
	}
	if (flag)	result += to_arabia[rome.substr(rome.size() - 1, 1)];
	return result;
}

string get_rome(int arabia) {
	string result = "";
	while (arabia) {
		for (auto iter = to_rome.rbegin(); iter != to_rome.rend(); iter++) {
			if (arabia >= iter->first) {
				result += iter->second;
				arabia -= iter->first;
				break;
			}
		}
	}
	return result;
}

int main() {
	to_rome[1] = "I";
	to_rome[5] = "V";
	to_rome[10] = "X";
	to_rome[50] = "L";
	to_rome[100] = "C";
	to_rome[500] = "D";
	to_rome[1000] = "M";

	to_rome[4] = "IV";
	to_rome[9] = "IX";
	to_rome[40] = "XL";
	to_rome[90] = "XC";
	to_rome[400] = "CD";
	to_rome[900] = "CM";

	to_arabia["I"] = 1;
	to_arabia["V"] = 5;
	to_arabia["X"] = 10;
	to_arabia["L"] = 50;
	to_arabia["C"] = 100;
	to_arabia["D"] = 500;
	to_arabia["M"] = 1000;

	to_arabia["IV"] = 4;
	to_arabia["IX"] = 9;
	to_arabia["XL"] = 40;
	to_arabia["XC"] = 90;
	to_arabia["CD"] = 400;
	to_arabia["CM"] = 900;

	string a, b;
	cin >> a >> b;
	
	int ia = get_arabia(a);
	int ib = get_arabia(b);
	int result = ia + ib;

	cout << result << "\n" << get_rome(result);
	return 0;
}