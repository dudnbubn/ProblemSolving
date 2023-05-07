#include <iostream>
#include <unordered_set>

using namespace std;

string files_to_erase[1000];
unordered_set<string> not_erase_name;
unordered_set<string> erase_name;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int TC;
	cin >> TC;

	int N1, N2;
	string file_name;
	string sub_file_name;
	while (TC--) {
		erase_name = {};
		not_erase_name = {};
		cin >> N1;
		for (int i = 0; i < N1; i++)	cin >> files_to_erase[i];

		cin >> N2;
		for (int i = 0; i < N2; i++) {
			cin >> file_name;
			sub_file_name = "";
			for (int j = 0; j < file_name.size(); j++) {
				sub_file_name = sub_file_name + file_name[j];
				not_erase_name.insert(sub_file_name);
			}
		}

		if (N2 == 0)	cout << 1 << "\n";
		else {
			for (int i = 0; i < N1; i++) {
				sub_file_name = "";
				for (int j = 0; j < files_to_erase[i].size(); j++) {
					sub_file_name = sub_file_name + files_to_erase[i][j];

					if (not_erase_name.find(sub_file_name) == not_erase_name.end()) {
						erase_name.insert(sub_file_name);
						break;
					}

					if (j == files_to_erase[i].size() - 1)	erase_name.insert(sub_file_name);
				}
			}

			cout << erase_name.size() << "\n";
		}
	}
	return 0;
}