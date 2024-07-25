#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);
void moveTo(int x, int y);

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;
    drawBoard(spaces);
    while (running)
    {
        playerMove(spaces, player);
        if(checkWinner(spaces, player, computer)){
            moveTo(0, 10);
            cout << "Player wins!" << endl;
            running = false;
            break;
        }
        if(checkTie(spaces)){
            moveTo(0, 10);
            cout << "It's a tie!" << endl;
            running = false;
            break;
        }
        computerMove(spaces, computer);
        if(checkWinner(spaces, computer, player)){
            moveTo(0, 10);
            cout << "Computer wins!" << endl;
            running = false;
            break;
        }
        if(checkTie(spaces)){
            moveTo(0, 10);
            cout << "It's a tie!" << endl;
            running = false;
            break;
        }
    }

    return 0;
}

void drawBoard(char *spaces)
{
    system("cls");
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    cout << "     |     |     " << '\n';

}

void playerMove(char *spaces, char player)
{
    int num;
    do
    {
        cout << "Enter a spot to place a marker (1-9): ";
        cin >> num;
        num--;
        if (spaces[num] == ' ')
        {
            spaces[num] = player;
            drawBoard(spaces);
            break;
        }
        else {
            cout << "Spot already taken, try again." << endl;
        }
    } while (num < 0 || num > 8);
}

void computerMove(char *spaces, char computer){
    int num ;
    srand(time(0));

    while (true){
        num = rand() % 9;
        if(spaces[num] == ' ')
        {
            spaces[num] = computer;
            drawBoard(spaces);
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer)
{
    // تحقق من جميع الاحتمالات للفوز
    if ((spaces[0] == player && spaces[1] == player && spaces[2] == player) ||
        (spaces[3] == player && spaces[4] == player && spaces[5] == player) ||
        (spaces[6] == player && spaces[7] == player && spaces[8] == player) ||
        (spaces[0] == player && spaces[3] == player && spaces[6] == player) ||
        (spaces[1] == player && spaces[4] == player && spaces[7] == player) ||
        (spaces[2] == player && spaces[5] == player && spaces[8] == player) ||
        (spaces[0] == player && spaces[4] == player && spaces[8] == player) ||
        (spaces[2] == player && spaces[4] == player && spaces[6] == player))
    {
        return true;
    }

    if ((spaces[0] == computer && spaces[1] == computer && spaces[2] == computer) ||
        (spaces[3] == computer && spaces[4] == computer && spaces[5] == computer) ||
        (spaces[6] == computer && spaces[7] == computer && spaces[8] == computer) ||
        (spaces[0] == computer && spaces[3] == computer && spaces[6] == computer) ||
        (spaces[1] == computer && spaces[4] == computer && spaces[7] == computer) ||
        (spaces[2] == computer && spaces[5] == computer && spaces[8] == computer) ||
        (spaces[0] == computer && spaces[4] == computer && spaces[8] == computer) ||
        (spaces[2] == computer && spaces[4] == computer && spaces[6] == computer))
    {
        return true;
    }

    return false;
}

bool checkTie(char *spaces)
{
    for (int i = 0; i < 9; ++i) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    return true;
}

void moveTo(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
