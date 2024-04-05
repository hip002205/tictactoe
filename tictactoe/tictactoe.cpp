/*
	tictactoe:copyright:lololol
*/

#include <iostream>
using namespace std;

void initial_step();
void display_output();
void input_P1();
void input_P2();
void game_play();
bool check();
bool retry();

char square[3][3];
int game_count = 0;
int flag = 0;

int main() {
	game_play();
}

void game_play() {
	initial_step();
	while (true) {
		display_output();
		if (check() == true) {
			cout << "×の勝ち" << endl;
			break;
		}
		input_P1();
		display_output();
		if (check() == true) {
			cout << "〇の勝ち" << endl;
			if (retry() == true) {
				game_play();
			}
			else if (retry() == false) {
				break;
			}
		}
		if (game_count > 8) {
			cout << "引き分け" << endl;
			if (check() == true) {
				cout << "〇の勝ち" << endl;
				if (retry() == true) {
					game_play();
				}
				else if (retry() == false) {
					break;
				}
			}
		}
		input_P2();
	}
}

void initial_step() {
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			square[i][j] = '-';
		}
	}
}

void display_output() {
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			cout << square[i][j] << " ";
		}
		cout << "\n";
	}
}


void input_P1() {
	while (1) {
		int x, y;
		cin >> x >> y;
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3) {
			if (square[x - 1][y - 1] == '-') {
				square[x - 1][y - 1] = 'O';
				game_count++;
				break;
			}
			else {
				cout << "同じマスには置けません。" << endl;
			}
		}
		else {
			cout << "範囲外" << endl;
		}
	}
}

void input_P2() {
	while (1) {
		int x, y;
		cin >> x >> y;
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3) {
			if (square[x - 1][y - 1] == '-') {
				square[x - 1][y - 1] = 'X';
				game_count++;
				break;
			}
			else {
				cout << "同じマスには置けません。" << endl;
			}
		}
		else {
			cout << "範囲外" << endl;
		}
	}
}

bool check() {
	if (square[0][0] == square[0][1] && square[0][1] == square[0][2] && square[0][0] != '-') {
		return true;
	}
	else if (square[1][0] == square[1][1] && square[1][1] == square[1][2] && square[1][0] != '-') {
		return true;
	}
	else if (square[2][0] == square[2][1] && square[2][1] == square[2][2] && square[2][0] != '-') {
		return true;
	}
	
	if (square[0][0] == square[1][0] && square[1][0] == square[2][0] && square[0][0] != '-') {
		return true;
	}
	else if (square[0][1] == square[1][1] && square[1][1] == square[2][1] && square[0][1] != '-') {
		return true;
	}
	else if (square[0][2] == square[1][2] && square[1][2] == square[2][2] && square[0][2] != '-') {
		return true;
	}

	if (square[1][1] != '-') {
		if (square[0][0] == square[1][1] && square[1][1] == square[2][2]) {
			return true;
		}
		else if (square[0][2] == square[1][1] && square[1][1] == square[2][0]) {
			return true;
		}
	}
}

bool retry() {
	char inpt;
	cout << "続けますか？続行:y 終了:n " << endl;
	cin >> inpt;

	while (1) {
		if (inpt == 'y') {
			return true;
		}
		else if (inpt == 'n') {
			return false;
			break;
		}
		else {
			cout << "正しい値を入力してください。" << endl;
		}
	}
}