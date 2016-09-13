//*********************************************************************
//
// main.cpp
//
// A test harness for the various classes.  The main entry point will
// probably change by the time I'm done.
//
// Author: Jeff Bassett
//
// Updates:
//    09/10/2016  Created
// 
//*********************************************************************


#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Game.h"
#include "ConsoleUI.h"


int main()
{
    Game game;
    ConsoleUI ui;

    const char* char_yes_no[] = {"yes", "no"};
    vector<string> yes_no(char_yes_no, char_yes_no + 2);
    string question("Play again?");

    int answer = 0;
    while(yes_no[answer] == "yes")
    {
        game.deal();
        game.play(ui);

        ui.text("Score...\n");
        game.score();
        game.displayState(ui, false);
        ui.text("\n");

        game.cleanup();
        answer = ui.choose("Play again?", yes_no, 0);
    }
}


