/*
	tictactoe.cpp:copyright:lololol
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char square[3][3];
int game_count;

void game_play();
void initial_step();
void print_screen();
void input_p();
void result();
bool check();
bool retry();

int main(){
    game_play();
}

void game_play() {
	initial_step();
	print_screen();

	while (true) {
		input_p();
		if (/*game_count >= 5 && */ check() == true) {
			result();
			if (retry() == false) {
				break;
			}
			else {
				game_play();
			}
		}
	}
}

void initial_step(){
    game_count = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            square[i][j] = '-';
        }
    }
}

void print_screen(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%c ", square[i][j]);
        }
        printf("\n");
    }
}

void input_p() {
    while (1) {
        int x = 0, y = 0;
        
        scanf_s("%d", &x);
        scanf_s("%d", &y);

        if (x >= 1 && x <= 3 && y >= 1 && y <= 3) {
            if (square[x - 1][y - 1] == '-') {
                if (game_count == 0 || game_count % 2 == 0) {
                    square[x - 1][y - 1] = 'O';
                }
                else {
                    square[x - 1][y - 1] = 'X';
                }
                game_count++;
                print_screen();
                break;
            }
            else {
                printf("同一マスです。\n");
            }
        }
        else {
            printf("範囲外です。\n");
        }
    }
}

bool check(){
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
		if (square[0][0] == square[1][1] && square[1][1] == square[2][2] && square[0][0] == square[2][2]) {
			return true;
		}
		else if (square[0][2] == square[1][1] && square[1][1] == square[2][0] && square[0][2] == square[2][0]) {
			return true;
		}
	}
	else {
		return false;
	}
}

bool retry() {
	char inpt;
	
	while (1) {
		printf("続けますか? yで続行,nで終了\n");
    	scanf_s("%s", &inpt);

		if (inpt == 'y') {
			return true;
		}
		else if (inpt == 'n') {
			return false;
		}
		else {
			printf("正しい値を入力してください。\n");
		}
	}
}

void result(){
	if (game_count % 2 == 1){
			printf("〇の勝ち\n");
	} else if (game_count > 8) {
		printf("引き分け\n");
		retry();
	} else {
		printf("×の勝ち\n");
	}
}