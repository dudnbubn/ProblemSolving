//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	string word;
//	while(true) {
//		cin.clear();
//		getline(cin, word);
//		if (cin.eof())
//			break;
//		int arr[4] = { 0, };
//		
//		for (int j = 0; j < word.size(); j++) {
//			if (word[j] >= 'a' && word[j] <= 'z')
//				arr[0]++;
//			else if (word[j] >= 'A' && word[j] <= 'Z')
//				arr[1]++;
//			else if (word[j] >= '0' && word[j] <= '9')
//				arr[2]++;
//			else if (word[j] == ' ')
//				arr[3]++;
//		}
//
//		for (int i : arr)
//			cout << i << " ";
//		cout << "\n";
//	}
//
//	return 0;
//}