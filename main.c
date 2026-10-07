#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char board[9];

void init_board() {
    for (int i = 0; i < 9; i++) board[i] = '1' + i;
}

void print_board() {
    printf("\n %c | %c | %c \n---|---|---\n %c | %c | %c \n---|---|---\n %c | %c | %c \n\n",
        board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);
}

int check_win() {
    int wins[8][3] = { {0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6} };
    for (int i = 0; i < 8; i++) {
        if (board[wins[i][0]] == board[wins[i][1]] && board[wins[i][1]] == board[wins[i][2]]) {
            return board[wins[i][0]] == 'X' ? 1 : 2;
        }
    }
    return 0;
}

int check_draw() {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') return 0;
    }
    return 1;
}

int minimax(int is_max) {
    int score = check_win();
    if (score == 2) return 10;
    if (score == 1) return -10;
    if (check_draw()) return 0;

    if (is_max) {
        int best = -1000;
        for (int i = 0; i < 9; i++) {
            if (board[i] != 'X' && board[i] != 'O') {
                char backup = board[i];
                board[i] = 'O';
                int val = minimax(0);
                board[i] = backup;
                if (val > best) best = val;
            }
        }
        return best;
    }
    else {
        int best = 1000;
        for (int i = 0; i < 9; i++) {
            if (board[i] != 'X' && board[i] != 'O') {
                char backup = board[i];
                board[i] = 'X';
                int val = minimax(1);
                board[i] = backup;
                if (val < best) best = val;
            }
        }
        return best;
    }
}

void execute_player_move() {
    int choice;
    while (1) {
        printf("Alege o pozitie (1-9): ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        choice--;
        if (choice >= 0 && choice <= 8 && board[choice] != 'X' && board[choice] != 'O') {
            board[choice] = 'X';
            break;
        }
        printf("Mutare invalida.\n");
    }
}

void execute_computer_move() {
    int best_val = -1000;
    int best_move = -1;
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            char backup = board[i];
            board[i] = 'O';
            int move_val = minimax(0);
            board[i] = backup;
            if (move_val > best_val) {
                best_move = i;
                best_val = move_val;
            }
        }
    }
    board[best_move] = 'O';
    printf("Computerul a ales pozitia %d\n", best_move + 1);
}

int play_game() {
    int status = 0, player_turn = 1;
    while (status == 0) {
        print_board();
        if (player_turn) execute_player_move();
        else execute_computer_move();

        status = check_win();
        if (!status && check_draw()) status = -1;
        player_turn = !player_turn;
    }
    print_board();
    return status;
}

int main() {
    init_board();
    int final_status = play_game();

    if (final_status == 1) printf("Ai castigat!\n");
    else if (final_status == 2) printf("Computerul a castigat!\n");
    else printf("Egalitate!\n");

    return 0;
}
