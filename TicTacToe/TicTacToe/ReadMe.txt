Jiwoo Seo | Lab 3: Tic-Tac-Toe Game

Encountered errors: At the beginning of the lab, source files and header files were not correctly registered/linked to the solution. 

Tested Cases:

'=>' indicates the errorlevel


1) wrong argument (wrong # of arguments, wrong name)

		H:\labs\lab3\lab3-jiwoos\lab3\Debug>lab3.exe arg1 arg2
		usage: lab3.exe TicTacToe
		=> 1 

		H:\labs\lab3\lab3-jiwoos\lab3\Debug>lab3.exe gomoku
		usage: lab3.exe TicTacToe
		=> 1

		correct behavior. 1 represents wrong argument return value.


2) game starts - valid inputs, result: draw
		H:\labs\lab3\lab3-jiwoos\lab3\Debug>lab3.exe TicTacToe

		4
		3
		2
		1
		0
		 0 1 2 3 4

		>> TURN: PLAYER O
		>> TYPE 'quit' OR 'x,y': 1,2

		4
		3
		2  O
		1
		0
		 0 1 2 3 4

		>> PLAYER O: 1,2;
		>> TURN: PLAYER X
		>> TYPE 'quit' OR 'x,y': 2,2

		4
		3
		2  O X
		1
		0
		 0 1 2 3 4

		>> PLAYER X: 2,2;
		>> TURN: PLAYER O
		>> TYPE 'quit' OR 'x,y': 3,3

		4
		3      O
		2  O X
		1
		0
		 0 1 2 3 4

		>> PLAYER O: 1,2; 3,3;
		>> TURN: PLAYER X
		>> TYPE 'quit' OR 'x,y': 1,1

		4
		3      O
		2  O X
		1  X
		0
		 0 1 2 3 4

		>> PLAYER X: 1,1; 2,2;
		>> TURN: PLAYER O
		>> TYPE 'quit' OR 'x,y': 1,3

		4
		3  O   O
		2  O X
		1  X
		0
		 0 1 2 3 4

		>> PLAYER O: 1,2; 1,3; 3,3;
		>> TURN: PLAYER X
		>> TYPE 'quit' OR 'x,y': 2,3

		4
		3  O X O
		2  O X
		1  X
		0
		 0 1 2 3 4

		>> PLAYER X: 1,1; 2,2; 2,3;
		>> TURN: PLAYER O
		>> TYPE 'quit' OR 'x,y': 2,1

		4
		3  O X O
		2  O X
		1  X O
		0
		 0 1 2 3 4

		>> PLAYER O: 2,1; 1,2; 1,3; 3,3;
		>> TURN: PLAYER X
		>> TYPE 'quit' OR 'x,y': 3,2

		4
		3  O X O
		2  O X X
		1  X O
		0
		 0 1 2 3 4

		>> PLAYER X: 1,1; 2,2; 3,2; 2,3;
		>> TURN: PLAYER O
		>> TYPE 'quit' OR 'x,y': 3,1

		4
		3  O X O
		2  O X X
		1  X O O
		0
		 0 1 2 3 4

		>> PLAYER O: 2,1; 3,1; 1,2; 1,3; 3,3;
		>> DRAW

		=> 3

		correct behavior. 3 is declared as 'result_draw' in returnValue enum.


3) game starts, invalid inputs, quit

		H:\labs\lab3\lab3-jiwoos\lab3\Debug>lab3.exe TicTacToe

		4
		3
		2
		1
		0
		 0 1 2 3 4

		>> TURN: PLAYER O
		>> TYPE 'quit' OR 'x,y': 5,5
		>> COORDINATE VALUES SHOULD RANGE FROM 1 TO 3                   // tells the user that coordinates should be in the range
		>> TYPE 'quit' OR 'x,y': 10,10
		>> COORDINATE VALUES SHOULD RANGE FROM 1 TO 3
		>> TYPE 'quit' OR 'x,y': invalid inputs
		>> TYPE 'quit' OR 'x,y': are ignored							// invalid inputs are simply ignored 

		4
		3      O
		2
		1
		0
		 0 1 2 3 4

		>> PLAYER O: 3,3;
		>> TURN: PLAYER X
		>> TYPE 'quit' OR 'x,y': 2,2
		>> COORDINATES '3,3' ARE TAKEN								// when the square is already taken, the message pops up to let user know.
		>> TYPE 'quit' OR 'x,y': 1,3 2,2							// when multiple coordinates are types, the program only accepts the first coordinate.

		4
		3  X   O
		2
		1
		0
		 0 1 2 3 4

		>> PLAYER X: 1,3;
		>> TURN: PLAYER O
		>> TYPE 'quit' OR 'x,y':                                  // quit command quits the game
		>> QUITTING THE GAME...

		=> 2


		correct behavior. 2 is declared as 'result_quit' in returnValue enum

4) game starts, one of the user wins 
		H:\labs\lab3\lab3-jiwoos\lab3\Debug>lab3.exe TicTacToe

		4
		3
		2
		1
		0
		 0 1 2 3 4

		>> TURN: PLAYER O
		>> TYPE 'quit' OR 'x,y': 1,1

		4
		3
		2
		1  O
		0
		 0 1 2 3 4

		>> PLAYER O: 1,1;
		>> TURN: PLAYER X
		>> TYPE 'quit' OR 'x,y': 2,1

		4
		3
		2
		1  O X
		0
		 0 1 2 3 4

		>> PLAYER X: 2,1;
		>> TURN: PLAYER O
		>> TYPE 'quit' OR 'x,y': 1,2

		4
		3
		2  O
		1  O X
		0
		 0 1 2 3 4

		>> PLAYER O: 1,1; 1,2;
		>> TURN: PLAYER X
		>> TYPE 'quit' OR 'x,y': 2,2

		4
		3
		2  O X
		1  O X
		0
		 0 1 2 3 4

		>> PLAYER X: 2,1; 2,2;
		>> TURN: PLAYER O
		>> TYPE 'quit' OR 'x,y': 1,3

		4
		3  O
		2  O X
		1  O X
		0
		 0 1 2 3 4

		>> PLAYER O: 1,1; 1,2; 1,3;
		>> PLAYER O WON

		=> 0

		correct behavior. if one of the user wins, the program should return success.

5) diagonal win, row win (column win is at #4)

		======== diagonal ==========
		4
		3      O
		2  X O
		1  O X
		0
		 0 1 2 3 4

		>> PLAYER O: 1,1; 2,2; 3,3;
		>> PLAYER O WON

		========== row ============
		4
		3
		2  X X
		1  O O O
		0
		 0 1 2 3 4

		>> PLAYER O: 1,1; 2,1; 3,1;
		>> PLAYER O WON

		=> 0

		correct behavior. if one of the user wins, the program should return success.