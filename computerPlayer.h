#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H
#include <bits/stdc++.h>
#include "board.h"
#include "player.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<char> vchar;
typedef vector<vchar> vvchar;
class ComputerPlayer : public Player{
    private:
        char piece;
        int difficulty;
        pair<int,int> minimax(Board b, int depth, char currPlayer);
    public:
        ComputerPlayer(char piece, int difficulty);
        Board play(Board b) override;
};
#endif
