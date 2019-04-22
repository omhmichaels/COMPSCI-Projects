/*
 *
 * # Title: Sudoku
 * # Description:
 * # Author: Michael Martin
 * # Class: COMPSCI 1
 * # 4-25-19
 */

// DESIGN //
/*
#
#
#
#
### Sudoku

Sudoku Rule Explaination


Board Layout
 > Create 9x9 grid
  - Use 1-9 and a-i
 > Create corressponding 3x3 boxes within the 9x9 box
 > Load in starter set for sudoku problem.
 > Create a completed solution for the sudoku problem.

Board Logic
 * GAME START *
  > Erase n amount of squares with numbers randomly according to sudoku logic.
  > Fill squares with user input IF it is TRUE to sudoku logic
  > IF not TRUE to sudoku logic ask for USER INPUT
  > When Squares are full player wins.

User InterFace
 > Intro Interface
  - Intro statement
  - Rules Prompt
  - Game Start Prompt
 > Game Play InterFace
  - Board Interface = Board Layout
  - Player Interface
   + Selection Options
   + Move confirmation
   + Quit
  - End game Interface
   + Winner Prompt
   + Play again?


Suduko Logic
  > User Input can only be places in a position IF
	- It is the correct input for that square.
*/

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include "userInterface.h"
using namespace std;

int NUM_CTRY = 5;             // Num countries supported
vector<string> ctryNames(NUM_CTRY); // Country names
vector<int>    ctryMins(NUM_CTRY);  // Mins TV watched daily



getInput userInput;
