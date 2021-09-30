// lab3.h
// author: Jiwoo Seo - jiwooseo@wustl.edu
// header file that has declarations of enums, functions, and global variables that are used in the source files (lab3.cpp, tictactoe.cpp)

#pragma once
#include "tictactoe.h"
#include <iostream>


const int expected_argument_count = 2;
const unsigned int minInclusive = 1;
const unsigned int maxExclusive = 4;
enum arrayIndex { program_name, game_name };
enum returnValue { success, not_expected_argnum, result_quit, result_draw, result_done };
enum gameStatus { coordinates_read_complete, coordinates_read_failed, quit, done, draw, progress };
int usageMsg(char*, char*);