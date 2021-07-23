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
//// 피연산자는 바로 출력, 연산자와 여는 괄호 '(' 는 스택에 저장
//// 스택에 저장되어 있는 연산자 중 현재 연산자의 우선순위보다 크거나 같으면 모두 pop
//// 닫는 괄호 ')' 가 나오면 여는 괄호까지 모든 연산자 pop
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