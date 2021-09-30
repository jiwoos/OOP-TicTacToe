// tictactoe.h
// author: Jiwoo Seo - jiwooseo@wustl.edu
// header file that has class declaration of tic-tac-toe game and the ostream operator for tic-tac-toe game

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <sstream>
#include "lab3.h"
#include "gamePieces.h"

class TicTacToeGame {
	friend std::ostream& operator<< (std::ostream& o, const TicTacToeGame& s);
public:
	TicTacToeGame();
	bool done();
	bool draw();
	int prompt(unsigned int&, unsigned int&);
	int turn();
	int play();
private:
	unsigned int width_;
	unsigned int height_;
	bool playerturn_;
	std::string winner_;
	std::vector<game_piece> vtr_;
};



std::ostream& operator<< (std::ostream& o, const TicTacToeGame& s);

