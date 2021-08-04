//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cout.tie(NULL);
//	cin.tie(NULL);
//
//	string s;
//	string suf = "";
//	vector<string> suffix;
//	cin >> s;
//	for (int i = s.size() - 1; i >= 0; i--) {
//		suf = s[i] + suf;
//		suffix.push_back(suf);
//	}
//	sort(suffix.begin(), suffix.end());
//	for (string s : suffix)
//		cout << s << "\n";
//
//	return 0;
//}