#include <bits/stdc++.h>
#include "HumanPlayer.h"
#include "board.h"
#include "player.h"
typedef long long ll;
using namespace std;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<char> vchar;
typedef vector<vchar> vvchar;
HumanPlayer::HumanPlayer(char piece) : Player(piece) {
    this->piece = piece;
}
Board HumanPlayer::play(Board b){
    cout<<"Player "<<piece<<"'s turn"<<endl;
    cout<<"enter a number between 1 and 7 to determine which column to place your piece"<<endl;
    int col; cin>>col;
    col--;
    while (col < 0 || col >= 7){
        cout<<"Invalid column, please enter again"<<endl;
        cin>>col;col--;
    }
    int row = b.place(piece, col);
    if (row == -1){
        cout<<"Column is full, please enter again"<<endl;
        cin>>col;col--;
    }
    return b;
}
