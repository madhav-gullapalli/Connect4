#include <bits/stdc++.h>
#include "board.cpp"
#include "board.h"
#include "player.h"
#include "humanPlayer.cpp"
#include "randomPlayer.cpp"
#include "computerPlayer.cpp"
typedef long long ll;
using namespace std;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<char> vchar;
typedef vector<vchar> vvchar;
//displays connect 4 board

int main() {
    Board board;
    vchar pieces = {'X', 'O'};
    board.dispBoard();
    HumanPlayer p1('X');
    cout<<"Who do you want to play against? (H for human, R for random, C for computer)"<<endl;
    char c; cin>>c;
    //declare p2 based on user input
    Player* p2;
    while(c != 'H' && c != 'R' && c != 'C'){
        cout<<"Invalid input, please enter H, R, or C"<<endl;
        cin>>c;
    }
    if(c == 'H'){
        p2 = new HumanPlayer('O');
    }else if(c == 'R'){
        p2 = new RandomPlayer('O');
    }
    else if(c == 'C'){
        int difficulty;
        cout<<"Enter difficulty level (1-3)"<<endl;
        cin>>difficulty;
        while(difficulty < 1 || difficulty > 3){
            cout<<"Invalid input, please enter a number between 1 and 3"<<endl;
            cin>>difficulty;
        }
        p2 = new ComputerPlayer('O', difficulty);
    }
    cout<<"Connect 4: game"<<endl;
    int turn = 0;
    while(true){
        if(turn%2 == 0){
            board = (p1.play(board));
        }
        else{
            board = (p2->play(board));
        }
        board.dispBoard();
        char winner = board.win();
        if(winner != '*'){
            cout<<"Player "<<winner<<" wins"<<endl;
            break;
        }
        turn++;
    }
}