// lab3.cpp
// author: Jiwoo Seo - jiwooseo@wustl.edu
// includes main and usageMsg functions. 
//   main() calls other functions in tictactoe.cpp to play the game.
//           Appropriate int value is returned according to the result of the game.
//   usageMsg() lets users know what to type in to start the program.

#include "lab3.h"
using namespace std;

int main(int argc, char* argv[])
{
    if (argc != expected_argument_count) 
    {
        char astring[] = "TicTacToe";
        char* toString = astring;
        return usageMsg(argv[program_name], toString);
       
    }
    else
    {
        if (string(argv[game_name]) != "TicTacToe")
        {
            char astring[] = "TicTacToe";
            char* toString = astring;
            return usageMsg(argv[program_name], toString);

        }
        else
        {
            TicTacToeGame game;
            int result = game.play();
            if (result == returnValue::result_done) {
                return success;
            }
            else {
                return result;
            }
        }
    }
    
    
   
   
}

int usageMsg(char* cs1, char* cs2)
{
    cout << "usage: " << cs1 << " " << cs2 << endl;
    return not_expected_argnum;
}