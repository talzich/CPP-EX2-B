// 
// AUTHORS: Tal Zichlinsky
//
// This file's purpose is to demonstrate the different methods of the Board class

#include "Board.hpp"

#include <iostream>
#include <string>


using namespace ariel;
using namespace std;

int main(void){

    Board b;

    b.post(0,0, Direction::Horizontal, "0123456789");
    b.show();

    return 0;
}