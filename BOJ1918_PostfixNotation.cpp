//#include <iostream>
//#include <stack>
//using namespace std;
//
//int getValue(char op) {
//	if (op == '(')
//		return 0;
//	else if (op == '*' || op == '/')
//		return 2;
//	else
//		return 1;
//}
//
//// �ǿ����ڴ� �ٷ� ���, �����ڿ� ���� ��ȣ '(' �� ���ÿ� ����
//// ���ÿ� ����Ǿ� �ִ� ������ �� ���� �������� �켱�������� ũ�ų� ������ ��� pop
//// �ݴ� ��ȣ ')' �� ������ ���� ��ȣ���� ��� ������ pop
//int main() {
//	ios_base::sync_with_stdio(false);
//	cout.tie(NULL);
//	cin.tie(NULL);
//
//	string infix;
//	stack<char> stk;
//	cin >> infix;
//	for (int i = 0; i < infix.size(); i++) {
//		if (infix[i] >= 'A' && infix[i] <= 'Z')
//			cout << infix[i];
//		else {
//			if (infix[i] == '(')
//				stk.push(infix[i]);
//			else if (infix[i] == ')') {
//				while (stk.top() != '(') {
//					cout << stk.top();
//					stk.pop();
//				}
//				stk.pop();
//			}
//			else {
//				while ((!stk.empty()) && (getValue(stk.top()) >= getValue(infix[i]))) {
//					cout << stk.top();
//					stk.pop();
//				}
//				stk.push(infix[i]);
//			}
//		}
//	}
//	while (!stk.empty()) {
//		cout << stk.top();
//		stk.pop();
//	}
//
//	return 0;
//}