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

const Direction HORI = Direction::Horizontal;
const Direction VERT = Direction::Vertical;

int main(void){

    Board b;
    unsigned int row;
    unsigned int col;
    string msg = "";

    // Startign introduction
    b.post(9,10, HORI, "Hello");
    b.post(10,10, HORI, "Harel!");
    b.show();

    system("read");
    b.post(7,3, HORI, "Oh, that's not it, right?");
    b.post(8,3, HORI, "I'll fix it than!");
    b.show();

    system("read");
    
    b.post(4,3, HORI, "Erel!");
    b.post(7,3, HORI, "____There, Done!_________");
    b.post(8,3, HORI, "_________________");
    b.show();

    b.post(8, 3, HORI, "Now look at that, my size changes dynamically!");
    b.show();
    system("read");

    b.post(8, 3, HORI, "Now look at that, my size changes dynamically!!");
    b.show();
    system("read");
    
    b.post(8, 3, HORI, "Now look at that, my size changes dynamically!!!");
    b.show();
    system("read");

    b.post(8, 3, HORI, "Now look at that, my size changes dynamically!!!!!!!!!!!!!!!!!!!!");
    b.show();
    system("read");

    b.post(9, 3, HORI, "I can also grow vertically! WATCH THAT!!!");
    b.show();
    system("read");

    //Printing arrow
    for(int i = 1; i < 9; i++){
        b.post(i, 13, HORI, "######");
    }
    b.post(9, 3, HORI,  "########################");
    b.post(10, 3, HORI, " ######################");   
    b.post(11, 3, HORI, "  ####################");   
    b.post(12, 3, HORI, "   ##################");  
    b.post(13, 3, HORI, "    ################");  
    b.post(14, 3, HORI, "     ##############");  
    b.post(15, 3, HORI, "      ############");
    b.post(16, 3, HORI, "       #########");
    b.post(17, 3, HORI, "        #######");
    b.post(18, 3, HORI, "         #####");
    b.post(19, 3, HORI, "          ###");
    b.post(20, 3, HORI, "           #");
    b.show();

    system("read");
    b.post(22, 3, HORI, "See that? Previous messages gets overwritten by new ones!");
    b.post(23, 3, HORI, "What would you like to write, and where?");
    b.show();

    // Interactive posting
    char dir = '0';
    while(1){
        cout << "Enter row number" << endl;
        cin >> row;

        cout << "Enter column number" << endl;
        cin >> col;

        // Clearing stdin
        cin.clear();
        fflush(stdin);

        while(dir != 'v' && dir != 'h'){
            cout << "Enter direction v or h" <<endl;
            cin >> dir;
        }

        // Clearing stdin
        cin.clear();
        fflush(stdin);

        cout << "Enter message" << endl;
        getline(cin, msg);

        switch (dir)
        {
        case 'v':
            b.post(row, col, VERT, msg);
            break;
        
        case 'h':
            b.post(row, col, HORI, msg);
            break;
        default:
            perror("Wrong direction has been entered");
            exit(1);
        }
        b.show();
        
        // So that in the next iteration, the direction choice will execute
        dir = '0';
    }
    return 0;
}