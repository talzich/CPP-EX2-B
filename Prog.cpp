// 
// AUTHORS: Tal Zichlinsky
//
// This file's purpose is to demonstrate the different methods of the Board class

#include "Board.hpp"
#include "snowman.hpp"

#include <iostream>
#include <ctime>
#include <string>


using namespace ariel;
using namespace std;

enum bad_inputs{ too_long, too_short, too_high, too_low};

const int GOOD_INPUT_LENGTH = 8;
const int MIDDLE = 4;

int produce_valid_input(){
    int c;
    string input = "";
    for (int i = 0; i < GOOD_INPUT_LENGTH; i++){
        srand(time(0));
        c = 1 + (rand() % 4); // Generating a random digit between 1 and 4 
        input += to_string(c);; // Converting the random digit to a char and concatinating it to the string 
    }
    return stoi(input);
}

int main(void){

    Board b;
    
    string my_snowman;
    for(int i = 0; i < 100; i++){
        my_snowman = snowman(produce_valid_input());
        b.post(i, MIDDLE, Direction::Horizontal, my_snowman);
    }
    b.show();

    return 0;
}