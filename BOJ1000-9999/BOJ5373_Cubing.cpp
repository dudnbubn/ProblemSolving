#include <iostream>

using namespace std;

char colors[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };
char faces[6][3][3];

void init() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				faces[i][j][k] = colors[i];
	}
}

void print_top() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << faces[0][i][j];
		cout << "\n";
	}
}

void rotate(char face[3][3], bool is_clockwise) {
	char save[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			save[i][j] = face[i][j];

	if (is_clockwise) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				face[i][j] = save[2 - j][i];
	}
	else {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				face[i][j] = save[j][2 - i];
	}
}

void up(bool is_clockwise) {
	char save[3];
	int current = 3;
	int prevs[3] = { 4, 2, 5 };
	if (!is_clockwise) {
		prevs[0] = 5;	prevs[2] = 4;
	}

	for (int i = 0; i < 3; i++)	save[i] = faces[current][0][i];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			faces[current][0][j] = faces[prevs[i]][0][j];
		}
		current = prevs[i];
	}
	for (int i = 0; i < 3; i++) faces[prevs[2]][0][i] = save[i];
	rotate(faces[0], is_clockwise);
}

void down(bool is_clockwise) {
	char save[3];
	int current = 2;

	int prevs[3] = { 4, 3, 5 };
	if (!is_clockwise) {
		prevs[0] = 5;	prevs[2] = 4;
	}
	for (int i = 0; i < 3; i++)	save[i] = faces[current][2][i];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			faces[current][2][j] = faces[prevs[i]][2][j];
		}
		current = prevs[i];
	}
	for (int i = 0; i < 3; i++) faces[prevs[2]][2][i] = save[i];
	rotate(faces[1], is_clockwise);
}

void front(bool is_clockwise) {
	char save[3];

	save[0] = faces[0][2][0];
	save[1] = faces[0][2][1];
	save[2] = faces[0][2][2];

	if (is_clockwise) {
		faces[0][2][0] = faces[4][2][2];
		faces[0][2][1] = faces[4][1][2];
		faces[0][2][2] = faces[4][0][2];

		faces[4][2][2] = faces[1][0][2];
		faces[4][1][2] = faces[1][0][1]; 
		faces[4][0][2] = faces[1][0][0];

		faces[1][0][2] = faces[5][0][0];
		faces[1][0][1] = faces[5][1][0];
		faces[1][0][0] = faces[5][2][0];

		faces[5][0][0] = save[0];
		faces[5][1][0] = save[1];
		faces[5][2][0] = save[2];
	}
	else {
		faces[0][2][0] = faces[5][0][0];
		faces[0][2][1] = faces[5][1][0];
		faces[0][2][2] = faces[5][2][0];

		faces[5][0][0] = faces[1][0][2];
		faces[5][1][0] = faces[1][0][1];
		faces[5][2][0] = faces[1][0][0];

		faces[1][0][2] = faces[4][2][2];
		faces[1][0][1] = faces[4][1][2];
		faces[1][0][0] = faces[4][0][2];

		faces[4][2][2] = save[0];
		faces[4][1][2] = save[1];
		faces[4][0][2] = save[2];
	}
	rotate(faces[2], is_clockwise);
}

void back(bool is_clockwise) {
	char save[3];

	save[0] = faces[0][0][2];
	save[1] = faces[0][0][1];
	save[2] = faces[0][0][0];

	if (is_clockwise) {
		faces[0][0][2] = faces[5][2][2];
		faces[0][0][1] = faces[5][1][2];
		faces[0][0][0] = faces[5][0][2];

		faces[5][2][2] = faces[1][2][0];
		faces[5][1][2] = faces[1][2][1];
		faces[5][0][2] = faces[1][2][2];

		faces[1][2][0] = faces[4][0][0];
		faces[1][2][1] = faces[4][1][0];
		faces[1][2][2] = faces[4][2][0];

		faces[4][0][0] = save[0];
		faces[4][1][0] = save[1];
		faces[4][2][0] = save[2];
	}
	else {
		faces[0][0][2] = faces[4][0][0];
		faces[0][0][1] = faces[4][1][0];
		faces[0][0][0] = faces[4][2][0];

		faces[4][0][0] = faces[1][2][0];
		faces[4][1][0] = faces[1][2][1];
		faces[4][2][0] = faces[1][2][2];

		faces[1][2][0] = faces[5][2][2];
		faces[1][2][1] = faces[5][1][2];
		faces[1][2][2] = faces[5][0][2];

		faces[5][2][2] = save[0];
		faces[5][1][2] = save[1];
		faces[5][0][2] = save[2];
	}
	rotate(faces[3], is_clockwise);
}

void left(bool is_clockwise) {
	char save[3];

	save[0] = faces[0][0][0];
	save[1] = faces[0][1][0];
	save[2] = faces[0][2][0];

	if (is_clockwise) {
		faces[0][0][0] = faces[3][2][2];
		faces[0][1][0] = faces[3][1][2];
		faces[0][2][0] = faces[3][0][2];

		faces[3][2][2] = faces[1][0][0];
		faces[3][1][2] = faces[1][1][0];
		faces[3][0][2] = faces[1][2][0];

		faces[1][0][0] = faces[2][0][0];
		faces[1][1][0] = faces[2][1][0];
		faces[1][2][0] = faces[2][2][0];

		faces[2][0][0] = save[0];
		faces[2][1][0] = save[1];
		faces[2][2][0] = save[2];
	}
	else {
		faces[0][0][0] = faces[2][0][0];
		faces[0][1][0] = faces[2][1][0];
		faces[0][2][0] = faces[2][2][0];

		faces[2][0][0] = faces[1][0][0];
		faces[2][1][0] = faces[1][1][0];
		faces[2][2][0] = faces[1][2][0];

		faces[1][0][0] = faces[3][2][2];
		faces[1][1][0] = faces[3][1][2];
		faces[1][2][0] = faces[3][0][2];

		faces[3][2][2] = save[0];
		faces[3][1][2] = save[1];
		faces[3][0][2] = save[2];
	}
	rotate(faces[4], is_clockwise);
}

void right(bool is_clockwise) {
	char save[3];

	save[0] = faces[0][2][2];
	save[1] = faces[0][1][2];
	save[2] = faces[0][0][2];

	if (is_clockwise) {
		faces[0][2][2] = faces[2][2][2];
		faces[0][1][2] = faces[2][1][2];
		faces[0][0][2] = faces[2][0][2];

		faces[2][2][2] = faces[1][2][2];
		faces[2][1][2] = faces[1][1][2];
		faces[2][0][2] = faces[1][0][2];

		faces[1][2][2] = faces[3][0][0];
		faces[1][1][2] = faces[3][1][0];
		faces[1][0][2] = faces[3][2][0];

		faces[3][0][0] = save[0];
		faces[3][1][0] = save[1];
		faces[3][2][0] = save[2];
	}
	else {
		faces[0][2][2] = faces[3][0][0];
		faces[0][1][2] = faces[3][1][0];
		faces[0][0][2] = faces[3][2][0];

		faces[3][0][0] = faces[1][2][2];
		faces[3][1][0] = faces[1][1][2];
		faces[3][2][0] = faces[1][0][2];

		faces[1][2][2] = faces[2][2][2];
		faces[1][1][2] = faces[2][1][2];
		faces[1][0][2] = faces[2][0][2];

		faces[2][2][2] = save[0];
		faces[2][1][2] = save[1];
		faces[2][0][2] = save[2];
	}
	rotate(faces[5], is_clockwise);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int TC;
	cin >> TC;

	int N;
	string command;
	while (TC--) {
		init();
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> command;
			bool is_clockwise = true;
			if (command[1] == '-')	is_clockwise = false;

			switch (command[0]) {
			case 'U':	up(is_clockwise);	break;
			case 'D':	down(is_clockwise);	break;
			case 'F':	front(is_clockwise);	break;
			case 'B':	back(is_clockwise);	break;
			case 'L':;	left(is_clockwise);	break;
			case 'R':	right(is_clockwise);	break;
			}
		}

		print_top();
	}
	return 0;
}