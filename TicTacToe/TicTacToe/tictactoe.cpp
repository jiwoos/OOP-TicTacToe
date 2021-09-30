// tictactoe.cpp
// author: Jiwoo Seo - jiwooseo@wustl.edu
// This source file has functions and constructors that are needed to play a tic-tac-toe game
// done() and draw() checks the currently occupied sqaures and tells if the game is over (by win or draw)
// prompt() lets user to put in coordinates values. It also allows user to quit and exit game.
// turn() receives input values from prompt() and determines if those values are valid.
//        is responsible for keeping track of the turn. O <-> X
// play() prints out the board, and calls turn() to keep the game on. 
//        checks done() and draw() to see if the user's latest move affected the result of the game.


#include "tictactoe.h"
using namespace std;
TicTacToeGame::TicTacToeGame()
    :width_(5), height_(5), playerturn_(true), winner_(" ")
{
    int dim = width_ * height_;
    for (int i = 0; i < dim; ++i) 
    {
        game_piece emptypiece(piece_color::no_color, "", " ");
        vtr_.push_back(emptypiece);
    }
};


bool TicTacToeGame::done() 
{

    bool returnVal = false; 
    // width*row# + col#
    // checking row
    for (unsigned int y = minInclusive; y < maxExclusive; ++y) 
    {
        if (vtr_[width_*y+1].display_ != " ") 
        {  
            returnVal = (vtr_[width_ * y + 1].display_ == vtr_[width_ * y + 2].display_) && (vtr_[width_ * y + 1].display_ == vtr_[width_ * y + 3].display_);
        }
        if (returnVal) 
        {
            winner_ = (vtr_[width_ * y + 1].display_);
            return returnVal;
        }
    }

    //checking col
    for (unsigned int x = 1; x < width_ - 1; ++x)
    {
        if (vtr_[width_ * 1 + x].display_ != " ") 
        {  
            returnVal = (vtr_[width_ * 1 + x].display_ == vtr_[width_ * 2 + x].display_) && (vtr_[width_ * 1 + x].display_ == vtr_[width_ * 3 + x].display_);
        }
        if (returnVal) 
        {
            winner_ = (vtr_[width_ * 1 + x].display_);
            return returnVal;
        }
    }

    //checking diagonal
    if (vtr_[width_ * 1 + 1].display_ != " ") {
        winner_ = (vtr_[width_ * 2 + 2].display_);
        returnVal = (vtr_[width_ * 1 + 1].display_ == vtr_[width_ * 2 + 2].display_) && (vtr_[width_ * 1 + 1].display_ == vtr_[width_ * 3 + 3].display_);
    }
    if (vtr_[width_ * 3 + 1].display_ != " ") {
        returnVal = (vtr_[width_ * 3 + 1].display_ == vtr_[width_ * 2 + 2].display_) && (vtr_[width_ * 3 + 1].display_ == vtr_[width_ * 1 + 3].display_);
        winner_ = (vtr_[width_ * 2 + 2].display_);
    }
    return returnVal;
}



bool TicTacToeGame::draw() 
{
   
    if (done() == true) 
    {
        return false;
    }
  
    for (unsigned int y = minInclusive; y < maxExclusive; ++y) 
    {
        for (unsigned int x = minInclusive; x < maxExclusive; ++x)
        {
            if (vtr_[(width_) * y + x].display_ == " ") 
            {
                return false;
            }
        }
    }
    return true;
}



int TicTacToeGame::prompt(unsigned int& x, unsigned int& y) 
{
    cout << ">> TYPE 'quit' OR 'x,y': " ;
    
    string userInput;
    cin >> userInput;
    cin.clear();
    cin.ignore(10000, '\n');

    if (userInput == "quit") 
    {
        cout << ">> QUITTING THE GAME..." << endl;
        return gameStatus::quit;
    }

    
    else 
    {
        
            for (size_t i = 0; i < userInput.size(); ++i)
            {
                
                if (userInput[i] == ',')
                {
                    userInput[i] = ' ';
                }
               
            }

            istringstream iss(userInput);
            if ((iss >> x) && (iss >> y))
            {
                return gameStatus::coordinates_read_complete;
            }
            else
            {
                return gameStatus::coordinates_read_failed;
            }
    }
       
}

int TicTacToeGame::turn() 
{
    playerturn_ = !playerturn_;
    string turnDP;
    if (playerturn_) 
    {
        turnDP = "X";
    }
    else 
    {
        turnDP = "O";
    }
    cout << ">> TURN: PLAYER " << turnDP << endl;

    vector<string> playerO, playerX;

    bool valid = false;
    unsigned int x, y;

    
    while (!valid) 
    {
        int promptVal = prompt(x, y);
        if (promptVal == gameStatus::quit) 
        {
            return gameStatus::quit;
        }

        if (promptVal == gameStatus::coordinates_read_complete) 
        {
            if (x >= maxExclusive || x < minInclusive || y >= maxExclusive || y < minInclusive) {
                cout << ">> COORDINATE VALUES SHOULD RANGE FROM 1 TO 3" << endl;
            }
            else if ((vtr_[width_*y+x].display_ == " ")) 
            {
                        vtr_[width_*y+x].display_ = turnDP;
                        cout << *this << endl;
                        cout << ">> PLAYER " << turnDP << ":" ;
                        for (unsigned int y = minInclusive; y < maxExclusive; ++y) 
                        {
                            for (unsigned int x = minInclusive; x < maxExclusive; ++x) 
                            {
                                if (vtr_[width_ * y + x].display_ == turnDP) 
                                {
                                    cout << " " << x << "," << y << ";";
                                }
                            }
                        }
                        cout << endl;
                        valid = true;
            }
            else {
                cout << ">> COORDINATES "<< "'" << x << "," << y << "'" << " ARE TAKEN" << endl;
            }
      
        }
    }
    return gameStatus::progress;
}

int TicTacToeGame::play() 
{
 
    cout << *this << endl;
    int status = gameStatus::progress;
    while (status == gameStatus::progress) 
    {
        if (turn() == gameStatus::quit) 
        {
            return returnValue::result_quit;
        }

        if (done())
        {
            status = returnValue::result_done;
            cout << ">> PLAYER " << winner_ << " WON" << endl; 
        }
        if (draw())
        {
            status = returnValue::result_draw;
            cout << ">> DRAW" << endl;
        }
    }

    return status;
}

ostream& operator<< (ostream& o, const TicTacToeGame& g) 
{
    o << endl;
    for (int i = g.height_ - 1; i >= 0; --i) 
    {
        o << i;
        for (unsigned int j = 0; j < g.width_; ++j) 
        {
            o << g.vtr_[g.width_ * i + j].display_ << " " ;
        }
        o << endl;
    }
    o << " ";
    for (unsigned int k = 0; k < g.width_; ++k) 
    {
        o <<  k << " ";
    }

    o << endl;
    return o;
}