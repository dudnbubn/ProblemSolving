#include <iostream>
#include <map>

using namespace std;

map<string, int> value;
map<string, int> mul;

int main() {
	value["black"] = 0;		mul["black"] = 1;
	value["brown"] = 1;		mul["brown"] = 10;
	value["red"] = 2;		mul["red"] = 100;
	value["orange"] = 3;	mul["orange"] = 1000;
	value["yellow"] = 4;	mul["yellow"] = 10000;
	value["green"] = 5;		mul["green"] = 100000;
	value["blue"] = 6;		mul["blue"] = 1000000;
	value["violet"] = 7;	mul["violet"] = 10000000;
	value["grey"] = 8;		mul["grey"] = 100000000;
	value["white"] = 9;		mul["white"] = 1000000000;

	string r1, r2, r3;
	cin >> r1 >> r2 >> r3;
	long long result = value[r1] * 10 + value[r2];
	result *= mul[r3];
	cout << result;

	return 0;
}