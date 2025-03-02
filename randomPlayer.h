#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H
#include <bits/stdc++.h>
#include "board.h"
#include "player.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<char> vchar;
typedef vector<vchar> vvchar;
class RandomPlayer : public Player{
    private:
        char piece;
    public:
        RandomPlayer(char piece);
        Board play(Board b) override;
};
#endif
