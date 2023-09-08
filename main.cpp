// Made by: JR-Bam
#include <iostream>
using namespace std;

void display (char board[][4]){
    for (int i = 0; i < 9; i++){
        cout << board[i/3][i%3];
        cout << ((i%3 == 2)? '\n': ' ');
        // trying to test printing a 2d array without nesting loops
        // probably more time intensive as division is pretty inefficient in programming
    }
}

// taking advantage of ascii values, might jeopardize readability
bool isWinningMove(char board[][4], int y, int x){
    const int SYMBOL_TIMES_3 = board[y][x] * 3;

    // all cases
    int sum = board[y][0] + board[y][1] + board[y][2];
    if (sum == SYMBOL_TIMES_3) return true;
    sum = board[0][x] + board[1][x] + board[2][x];

    // diagonals
    if (y == x)
        sum = board[0][0] + board[1][1] + board[2][2];
    if (x + y == 2)
        sum = board[0][2] + board[1][1] + board[2][0];

    if (sum == SYMBOL_TIMES_3) return true;

    return false;
}

int main() {
    char BOARD[3][4] = {"---", "---", "---"};
    /* Truthfully, I'm way too lazy to type "'-'," 9 times. It's with this laziness
     * that I discovered strings technically have a size of whatever you typed in +1.
     * I think it's because a special character to indicate whenever the data inside
     * a string variable ends is always appended at the end, because that would explain
     * the dynamic nature of a string. I don't know, but it definitely forced me to
     * allocate 4 char memory slots now for the column.
     */
    int round = 0, x, y;
    int player;
    bool noWinner = true;

    while (round < 9){
        cout << '\n';
        round++;
        player = 1 + (1 * round % 2 == 0);
        display(BOARD);

        cout << "Player " << player << '\n';
        cout << "Please enter your coordinates (x, y): ";
        cin >> x >> y;

        if (BOARD[y][x] != '-' || x > 2 || x < 0 || y > 2 || y < 0){
            cout << "Enter valid coordinates.\n";
            round--;
            continue;
        }

        BOARD[y][x] = (round % 2 == 0)? 'X': 'O';

        if (isWinningMove(BOARD, y, x)){
            display(BOARD);
            cout << "Congratulations Player " << player << ", you won!\n";
            noWinner = false;
            break;
        }
    }

    if (round == 9 && noWinner) cout << "No possible winners.\n";

    return 0;
}
