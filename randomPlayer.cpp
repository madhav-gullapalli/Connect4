#include <bits/stdc++.h>
#include "randomPlayer.h"
#include "player.cpp"
#include "board.h"
typedef long long ll;
using namespace std;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<char> vchar;
typedef vector<vchar> vvchar;

RandomPlayer::RandomPlayer(char piece) : Player(piece) {
    this->piece = piece;
}
Board RandomPlayer::play(Board b){
    cout<<"Player "<<piece<<"'s turn"<<endl;
    srand(time(0));
    int col = rand() % 7;
    col--;
    int row = b.place(piece, col);
    return b;
}
