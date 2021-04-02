// 
// AUTHORS: Tal Zichlinsky
//
// This file's purpose is to demonstrate the different methods of the Board class

#include "Board.hpp"

#include <iostream>
#include <string>
#include <thread>

using namespace ariel;
using namespace std;

const Direction HORI = HORI;


int main(void){

    Board b;
    unsigned int row;
    unsigned int col;
    string msg = "";

    b.post(3,5, HORI, "Hello");
    b.post(4,5, HORI, "Harel!");
    b.show();

    system("read");
    b.post(7,5, HORI, "Oh, that's not it, right?");
    b.post(8,5, HORI, "I'll fix it than!");
    b.show();

    system("read");
    
    b.post(4,5, HORI, "Erel!");
    b.post(7,5, HORI, "____There, Done!_________");
    b.post(8,5, HORI, "_________________");
    b.show();

    b.post(8, 5, HORI, "Now look at that, my size changes dynamically!");
    b.show();
    system("read");

    b.post(8, 5, HORI, "Now look at that, my size changes dynamically!!");
    b.show();
    system("read");
    
    b.post(8, 5, HORI, "Now look at that, my size changes dynamically!!!");
    b.show();
    system("read");

    b.post(8, 5, HORI, "Now look at that, my size changes dynamically!!!!!!!!!!!!!!!!!!!!");
    b.show();
    system("read");

    b.post(9, 5, HORI, "I can also grow vertically! WATCH THAT!!!");
    b.show();
    system("read");

    for(int i = 1; i < 9; i++){
        b.post(i, 13, HORI, "######");
    }
    b.post(9, 5, HORI,  "########################");
    b.post(10, 5, HORI, " ######################");   
    b.post(11, 5, HORI, "  ####################");   
    b.post(12, 5, HORI, "   ##################");  
    b.post(13, 5, HORI, "    ################");  
    b.post(14, 5, HORI, "     ##############");  
    b.post(15, 5, HORI, "      ############");
    b.post(16, 5, HORI, "       #########");
    b.post(17, 5, HORI, "        #######");
    b.post(18, 5, HORI, "         #####");
    b.post(19, 5, HORI, "          ###");
    b.post(20, 5, HORI, "           #");
    b.show();

    system("read");
    b.post(22, 5, HORI, "See that? Previous messages gets overwritten by new ones!");
    b.post(23, 5, HORI, "What would you like to write, and where?");
    b.show();

    while(1){
        cout << "Enter row number" << endl;
        cin >> row;

        cout << "Enter column number" << endl;
        cin >> col;

        cin.clear();
        fflush(stdin);
        cout << "Enter message" << endl;
        getline(cin, msg);

        
        b.post(row, col, HORI, msg);
        b.show();
    }
    return 0;
}