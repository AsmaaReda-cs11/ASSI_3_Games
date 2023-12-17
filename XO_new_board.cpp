#include<iostream>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"
using namespace std;

XO_new_board::XO_new_board ()
{
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool XO_new_board:: update_board (int x, int y, char mark)
{
// Only update if move is valid & board[x][y] hasnot accessed before
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}


void XO_new_board:: display_board()
{
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(4) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
bool XO_new_board:: is_winner()
{
    if(n_moves!=24) {

        for (int i = 0; i < 5; i++) {
            if (board[i][0] == 'x' && board[i][1] == 'x' && board[i][2] == 'x')
                counterXs += 1;
            if (board[i][1] == 'x' && board[i][2] == 'x' && board[i][3] == 'x')
                counterXs += 1;
            if (board[i][2] == 'x' && board[i][3] == 'x' && board[i][4] == 'x')
                counterXs += 1;
            if (board[i][0] == 'o' && board[i][1] == 'o' && board[i][2] == 'o')
                counter0s += 1;
            if (board[i][1] == 'o' && board[i][2] == 'o' && board[i][3] == 'o')
                counter0s += 1;
            if (board[i][2] == 'o' && board[i][3] == 'o' && board[i][4] == 'o')
                counter0s += 1;
        }
        for (int j = 0; j < 5; j++) {
            if (board[0][j] == 'x' && board[1][j] == 'x' && board[2][j] == 'x')
                counterXs += 1;
            if (board[1][j] == 'x' && board[2][j] == 'x' && board[3][j] == 'x')
                counterXs += 1;
            if (board[2][j] == 'x' && board[3][j] == 'x' && board[4][j] == 'x')
                counterXs += 1;
            if (board[0][j] == 'o' && board[1][j] == 'o' && board[2][j] == 'o')
                counter0s += 1;
            if (board[1][j] == 'o' && board[2][j] == 'o' && board[3][j] == 'o')
                counter0s += 1;
            if (board[2][j] == 'o' && board[3][j] == 'o' && board[4][j] == 'o')
                counter0s += 1;
        }
        //looping through off and principle diagonals
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'x' && board[i + 1][j + 1] == 'x' && board[i + 2][j + 2] == 'x')
                    counterXs += 1;
                if (board[i][4 - j] == 'x' && board[i + 1][3 - j] == 'x' && board[i + 2][2 - j] == 'x')
                    counterXs += 1;
                if (board[i][j] == 'o' && board[i + 1][j + 1] == 'o' && board[i + 2][j + 2] == 'o')
                    counter0s += 1;
                if (board[i][j] == 'o' && board[i + 1][j + 1] == 'o' && board[i + 2][j + 2] == 'o')
                    counter0s += 1;
            }
        }
    }
    if (counter0s==counterXs)
        return false;
    else
    {
        if(counter0s>counterXs)
        {
            cout<<"player o wins the game";
            return true;
        }
        else if(counter0s<counterXs)
        {
            cout<<"player x wins the game ";
            return true;
        }
    }
}
bool XO_new_board:: is_draw()
{
    return (n_moves == 24 && !is_winner());
}
bool XO_new_board:: game_is_over()
{
    return (n_moves == 24);
}

