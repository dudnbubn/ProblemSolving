#include <iostream>
using namespace std;

int n;

void Recur(int k) {
	for (int i = 0; i < k; i++)	cout << "____";
	cout << "\"����Լ��� ������?\"\n";
	for (int i = 0; i < k; i++)	cout << "____";
	if (k == n) {
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		for (int i = 0; i < k; i++)	cout << "____";
		cout << "��� �亯�Ͽ���.\n";
		return;
	}
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	for (int i = 0; i < k; i++)	cout << "____";
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	for (int i = 0; i < k; i++)	cout << "____";
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
	Recur(k + 1);
	for (int i = 0; i < k; i++)	cout << "____";
	cout << "��� �亯�Ͽ���.\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	Recur(0);
	return 0;
}