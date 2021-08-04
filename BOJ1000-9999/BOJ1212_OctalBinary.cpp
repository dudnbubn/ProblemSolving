//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	string oct, bin = "";
//	cin >> oct;
//	for (int i = 0; i < oct.size(); i++) {
//		switch (oct[i]) {
//		case '0':	bin += "000"; break;
//		case '1':	bin += "001"; break;
//		case '2':	bin += "010"; break;
//		case '3':	bin += "011"; break;
//		case '4':	bin += "100"; break;
//		case '5':	bin += "101"; break;
//		case '6':	bin += "110"; break;
//		case '7':	bin += "111"; break;
//		}
//	}
//	if (bin[0] == '1')	cout << bin;
//	else if (bin[1] == '1') cout << bin.substr(1, bin.size() - 1);
//	else	cout << bin.substr(2, bin.size() - 2);
//	return 0;
//}