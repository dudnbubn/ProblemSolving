//#include <iostream>
//#include <stack>
//using namespace std;
//
//int main() {
//	int n;
//	int arr[26] = { 0, };
//	string exp;
//	stack<double> stk;
//	cin >> n;
//	cin >> exp;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	// 피연산자가 나오면 스택에 저장,
//	// 연산자가 나오면 스택에서 2개를 뽑아서 연산. (top에 위치한 피연산자가 b)
//	for (int i = 0; i < exp.size(); i++) {
//		if (exp[i] >= 'A' && exp[i] <= 'Z') {
//			stk.push((double)arr[exp[i] - 'A']);
//		}
//		else {
//			double b = stk.top();
//			stk.pop();
//			double a = stk.top();
//			stk.pop();
//			
//			switch (exp[i]) {
//			case '+':
//				stk.push((double)a + b);
//				break;
//			case '-':
//				stk.push((double)a - b);
//				break;
//			case '*':
//				stk.push((double)a * b);
//				break;
//			case '/':
//				stk.push((double)a / b);
//				break;
//			}
//		}
//	}
//
//	double answer = stk.top();
//	cout.precision(2);
//	cout << fixed << answer;
//	
//	return 0;
//}