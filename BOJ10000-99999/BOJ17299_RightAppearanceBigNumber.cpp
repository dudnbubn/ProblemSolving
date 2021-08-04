//#include <iostream>
//#include <stack>
//using namespace std;
//
//int A[1000001];
//int appear[1000001] = { 0, };
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n;
//	stack<int> stk;	// A[i]�� ������ ���ڸ� ����
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> A[i];
//		appear[A[i]]++;
//	}
//
//	for (int i = n - 1; i >= 0; i--) {
//		if (stk.empty()) {
//			stk.push(A[i]);
//			A[i] = -1;
//		}
//		else {
//			// A[i] �������� ����Ƚ���� A[i] ���� ū ���
//			if (appear[stk.top()] > appear[A[i]]) {
//				int temp = stk.top();
//				stk.push(A[i]);
//				A[i] = temp;
//			}
//			else {
//				// A[i] �������� ����Ƚ���� A[i] ���� ���� ��� ������ ���鼭 ã��
//				while ((!stk.empty()) && (appear[stk.top()] <= appear[A[i]]))
//					stk.pop();
//				// A[i] ���� ����Ƚ���� ū ���� �����Ƿ� A[i] = -1
//				if (stk.empty()) {
//					stk.push(A[i]);
//					A[i] = -1;
//				}
//				// A[i] ���� ����Ƚ���� ū ���� A[i]�� ����
//				else {
//					int temp = stk.top();
//					stk.push(A[i]);
//					A[i] = temp;
//				}
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//		cout << A[i] << " ";
//
//	return 0;
//}