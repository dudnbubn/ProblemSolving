//// �������� ���ڿ��� �ް� ���ڿ��� ũ�Ⱑ 3�� ����� �ǵ��� ������ �տ� '0'�� �ٿ��ش�.
//// 3���� ��� 8������ ��ȯ�Ѵ�.
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	string bin;
//	cin >> bin;
//	int sz = bin.size() % 3;
//	if (sz != 0) {
//		for (int i = 0; i < 3 - sz; i++)
//			bin = '0' + bin;
//	}
//	
//	string oct = "";
//	for (int i = 0; i < bin.size(); i+=3) {
//		string temp = bin.substr(i, 3);
//		if (temp == "000")	oct += '0';
//		else if (temp == "001")	oct += '1';
//		else if (temp == "010")	oct += '2';
//		else if (temp == "011")	oct += '3';
//		else if (temp == "100")	oct += '4';
//		else if (temp == "101")	oct += '5';
//		else if (temp == "110")	oct += '6';
//		else if (temp == "111")	oct += '7';
//		
//	}
//	cout << oct;
//	return 0;
//}