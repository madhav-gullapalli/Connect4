#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include <bits/stdc++.h>
#include "board.h"
#include "player.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<char> vchar;
typedef vector<vchar> vvchar;
class HumanPlayer : public Player{
    private:
        char piece;
    public:
        HumanPlayer(char piece);
        Board play(Board b) override;
};
#endif
