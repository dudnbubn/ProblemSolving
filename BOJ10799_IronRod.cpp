//#include <iostream>
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	string input;
//	cin >> input;
//	int cnt = 0;
//	int rod = 0;
//	for (int i = 0; i < input.size(); i++) {
//		// '(' �� �� ���� ��ȣ�� ')' �̸� ������, �ƴϸ� �踷���
//		if (input[i] == '(') {
//			if (input[i + 1] == ')') {
//				cnt += rod;
//				i++;
//			}
//			else
//				rod++;
//		}
//		// ')' �� �� �踷��� ��. �������� �ݴ� ��ȣ�� 17�࿡�� ó��
//		else {
//			cnt++;
//			rod--;
//		}
//	}
//	cout << cnt;
//
//	return 0;
//}