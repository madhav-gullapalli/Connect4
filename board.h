#ifndef BOARD_H
#define BOARD_H
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<char> vchar;
typedef vector<vchar> vvchar;
class Board{
    private:
        vvchar board;
    public:
        Board();
        int place(char player, int col);
        int del(int col);
        void dispBoard();
        char win();
        char won();
        int score(char player);
};
#endif
