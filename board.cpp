#include <bits/stdc++.h>
#include "board.h"
typedef long long ll;
using namespace std;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<char> vchar;
typedef vector<vchar> vvchar;
Board::Board() {
    board = vvchar(6, vchar(7, '*'));
}
int Board::place(char player, int col) {
    for (int i = 5; i >= 0; i--) {
        if (board[i][col] == '*') {
            board[i][col] = player;
            return i;
        }
    }
    return -1;
}
int Board::del(int col) {
    for (int i = 0; i <= 5; i++) {
        if (board[i][col] != '*') {
            board[i][col] = '*';
            return i;
        }
    }
    return -1;
}

void Board::dispBoard() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

char Board::win() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] != '*') {
                if (j + 3 < 7 && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3]) {
                    return board[i][j];
                }
                if (i + 3 < 6 && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j]) {
                    return board[i][j];
                }
                if (i + 3 < 6 && j + 3 < 7 && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3]) {
                    return board[i][j];
                }
                if (i - 3 >= 0 && j + 3 < 7 && board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2] && board[i][j] == board[i - 3][j + 3]) {
                    return board[i][j];
                }
            }
        }
    }
    return '*';
    
}
char Board::won(){
    if(board[5][0]=='X' || board[5][0]=='O' || board[5][0]=='*'){
        return '*';
    }
    return board[5][0];
}
int Board::score(char player){
    if(win() == player){
        return 1e9;
    }
    int score = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            if(board[i][j] != player){
                continue;
            }
            if(j == 0 || board[i][j-1] != player){
                int getLen = 0;
                for(int k = 0; k < 4; k++){
                    if(j + k < 7 && board[i][j + k] == player){
                        getLen++;
                        continue;
                    }
                    break;
                }
                int cansee = 2;
                int maxSpot = j + getLen - 1;
                if(j + 3 < 7){
                    for(int k = 0; k < 4; k++){
                        if(board[i][j + k] != '*' && board[i][j+k] != player){
                            cansee--;
                            break;
                        }
                    }
                }else{
                    cansee--;
                }
                if(maxSpot > 2){
                    for(int k = 0; k < 4; k++){
                        if(board[i][maxSpot - k] != '*' && board[i][maxSpot - k] != player){
                            cansee--;
                            break;
                        }
                    }
                }else{
                    cansee--;
                }
                score += getLen * getLen * getLen* cansee;
            }
            if(i == 0 || board[i-1][j] != player){
                int getLen = 0;
                for(int k = 0; k < 4; k++){
                    if(i + k < 6 && board[i + k][j] == player){
                        getLen++;
                        continue;
                    }
                    break;
                }
                int cansee = 2;
                int maxSpot = i + getLen - 1;
                if(i + 3 < 6){
                    for(int k = 0; k < 4; k++){
                        if(board[i + k][j] != '*' && board[i + k][j] != player){
                            cansee--;
                            break;
                        }
                    }
                }else{
                    cansee--;
                }
                if(maxSpot > 2){
                    for(int k = 0; k < 4; k++){
                        if(board[maxSpot - k][j] != '*' && board[maxSpot - k][j] != player){
                            cansee--;
                            break;
                        }
                    }
                }else{
                    cansee--;
                }
                score += getLen * getLen * getLen * cansee;
            }
            if(i == 0 || j == 0 || board[i-1][j-1] != player){
                int getLen = 0;
                for(int k = 0; k < 4; k++){
                    if(i + k < 6 && j + k < 7 && board[i + k][j + k] == player){
                        getLen++;
                        continue;
                    }
                    break;
                }
                int cansee = 2;
                int maxSpotI = i + getLen - 1;
                int maxSpotJ = j + getLen - 1;
                if(i + 3 < 6 && j + 3 < 7){
                    for(int k = 0; k < 4; k++){
                        if(board[i + k][j + k] != '*' && board[i + k][j + k] != player){
                            cansee--;
                            break;
                        }
                    }
                }else{
                    cansee--;
                }
                if(maxSpotI > 2 && maxSpotJ > 2){
                    for(int k = 0; k < 4; k++){
                        if(board[maxSpotI - k][maxSpotJ - k] != '*' && board[maxSpotI - k][maxSpotJ - k] != player){
                            cansee--;
                            break;
                        }
                    }
                }else{
                    cansee--;
                }
                score += getLen * getLen * getLen * cansee;
            }

            if(i == 0 || j == 6 || board[i-1][j+1] != player){
                int getLen = 0;
                for(int k = 0; k < 4; k++){
                    if(i + k < 6 && j - k >= 0 && board[i + k][j - k] == player){
                        getLen++;
                        continue;
                    }
                    break;
                }
                int cansee = 2;
                int maxSpotI = i + getLen - 1;
                int maxSpotJ = j - getLen + 1;
                if(i + 3 < 6 && j - 3 >= 0){
                    for(int k = 0; k < 4; k++){
                        if(board[i + k][j - k] != '*' && board[i + k][j - k] != player){
                            cansee--;
                            break;
                        }
                    }
                }else{
                    cansee--;
                }
                if(maxSpotI > 2 && maxSpotJ < 4){
                    for(int k = 0; k < 4; k++){
                        if(board[maxSpotI - k][maxSpotJ + k] != '*' && board[maxSpotI - k][maxSpotJ + k] != player){
                            cansee--;
                            break;
                        }
                    }
                }else{
                    cansee--;
                }
                score += getLen * getLen * getLen * cansee;
            }
        }
    }
    return score;
}

