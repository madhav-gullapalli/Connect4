#ifndef PLAYER_H
#define PLAYER_H
#include <bits/stdc++.h>
#include "board.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<char> vchar;
typedef vector<vchar> vvchar;
class Player{
    protected:
        char piece;
    public:
        Player(char piece);
        virtual Board play(Board b) = 0;
};
#endif
