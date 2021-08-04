//#include <iostream>
//using namespace std;
//
//bool set[21] = { 0, };
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int m;
//	string cmd;
//	int x;
//	cin >> m;
//	for (int i = 0; i < m; i++) {
//		cin >> cmd;
//
//		if (cmd == "add") {
//			cin >> x;
//			set[x] = 1;
//		}
//		else if (cmd == "remove") {
//			cin >> x;
//			set[x] = 0;
//		}
//		else if (cmd == "check") {
//			cin >> x;
//			cout << set[x] << "\n";
//		}
//		else if (cmd == "toggle") {
//			cin >> x;
//			set[x] = !set[x];
//		}
//		else if (cmd == "all") {
//			for (int i = 1; i < 21; i++)
//				set[i] = 1;
//		}
//		else if (cmd == "empty") {
//			for (int i = 1; i < 21; i++)
//				set[i] = 0;
//		}
//	}
//	return 0;
//}