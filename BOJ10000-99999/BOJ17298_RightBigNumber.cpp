//#include <iostream>
//#include <stack>
//using namespace std;
//
//int A[1000000];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int n;
//	stack<int> stk;
//	cin >> n;
//	for (int i = 0; i < n; i++)	
//		cin >> A[i];
//
//	// �迭�� �ں��� ������ ��. ���ÿ��� A[i]���� �����ʿ� �ִ� ���� �����
//	for (int i = n - 1; i >= 0; i--) {
//		// ������ ��������� �����ʿ� ū ���� �����Ƿ� -1
//		if (stk.empty()) {
//			stk.push(A[i]);
//			A[i] = -1;
//		}
//		else {
//			// A[i]�� �����ʿ� �����鼭 A[i]���� ū �� �߿��� ���� ���ʿ� �ִ� ��
//			if (stk.top() > A[i]) {
//				int temp = stk.top();
//				stk.push(A[i]);
//				A[i] = temp;
//			}
//			else {
//				// A[i]���� ���� ���� ���ֹ���
//				while ((!stk.empty()) && (stk.top() <= A[i]))
//					stk.pop();
//				// ������ ��������� �����ʿ� ū ���� �����Ƿ� -1
//				if (stk.empty()) {
//					stk.push(A[i]);
//					A[i] = -1;
//				}
//				// A[i]���� ���� ���� �������Ƿ� ���� ���� 
//				// A[i]�� �����ʿ� �����鼭 A[i]���� ū �� �߿��� ���� ���ʿ� �ִ� ��
//				else {
//					int temp = stk.top();
//					stk.push(A[i]);
//					A[i] = temp;
//				}
//			}
//		}
//	}
//	
//	for (int i = 0; i < n; i++)
//		cout << A[i] << " ";
//
//	return 0;
//}