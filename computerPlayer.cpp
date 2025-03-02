#include <bits/stdc++.h>
#include "computerPlayer.h"
#include "player.h"
#include "board.h"
typedef long long ll;
using namespace std;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<char> vchar;
typedef vector<vchar> vvchar;

ComputerPlayer::ComputerPlayer(char piece,int difficulty) : Player(piece) {
    this->piece = piece;
    this->difficulty = difficulty;
}
pair<int,int> ComputerPlayer::minimax(Board b, int depth, char currPlayer){
    char oppPlayer = (currPlayer == 'X') ? 'O' : 'X';
    if(depth == 0|| b.win() != '*'){
        return make_pair(-1, b.score(currPlayer)-b.score(oppPlayer));
    }
    int bestScore = 15e8;
    int bestCol = -1;
    for(int i = 0; i < 7; i++){
        if(b.place(currPlayer, i) != -1){
            int cScore = (b.score(currPlayer) - b.score(oppPlayer))*-1;
            if(cScore > bestScore){
                b.del(i);
                continue;
            }
            pair<int,int> score = minimax(b, depth - 1, oppPlayer);
            if(score.second < bestScore){
                bestScore = score.second;
                bestCol = i;
            }
            b.del(i);
        }
    }
    return make_pair(bestCol, bestScore * -1);
}
Board ComputerPlayer::play(Board b){
    cout<<"Player "<<piece<<"'s turn"<<endl;
    vll diffToDepth = {1, 3, 7};
    int dep = diffToDepth[this->difficulty - 1];
    pair<int,int> move = minimax(b, dep, piece);
    b.place(piece, move.first);
    return b;
}
