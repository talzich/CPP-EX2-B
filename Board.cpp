//
// AUTHOURS: Tal Zichlinsky
// This file will be used to build a message board class, as described in this assignments README document (https://github.com/cpp-exercises/messageboard-a)

#include "Board.hpp"

#include <exception>
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace ariel;

namespace ariel
{   
    // Default and minimal size for a message board
    const int DEFAULT_SIZE = 100;
    const int MIN_SIZE = 1;

    
    // Default constructor
    Board::Board(){

        // No size is given as parameter so initializing to default size
        rows = DEFAULT_SIZE;
        cols = DEFAULT_SIZE;

        // Initializing vector with number of rows
        board.resize(rows);
        
        // Initializing each row of the vector with number of columns and the empty space char
        for(int i = 0; i < this->rows; i++){
            board[i].resize(cols, EMPTY_SPACE);
        }
    }

    // Two parameter constructor
    Board::Board(unsigned int rows, unsigned int cols){   
        
        if(rows < MIN_SIZE){
            throw invalid_argument("Invalid input: " + to_string(rows));
        }

        if(cols < MIN_SIZE){
            throw invalid_argument("Invalid input: " + to_string(cols));
        }

        this->rows = rows;
        this->cols = cols;
    }

    // Single parameter constructor
    Board::Board(unsigned int size){   
        
        if(size < MIN_SIZE){
            throw invalid_argument("Invalid input: " + to_string(rows));
        }

        this->rows = size;
        this->cols = size;
    }
    
    // Destructor
    Board::~Board(){
        cout << "Destructing: " << this->rows << "X" << this->cols << endl;
    }

    // This method will get row, column, direction and a message as parameters and posts the message in the 
    // appropriate location and diraction in this message board
    int Board::post(unsigned int row, unsigned int col, Direction dir, string msg){
        return 0;
    }

    // This method get row, column, direction and length of a message as parameters and returns the message in the 
    // appropriate location and diraction in this message board
    string Board::read(unsigned int row, unsigned int col, Direction dir, unsigned int len){
        return " ";
    }

    // This message will print out the entire message board
    void Board::show(){}

    int Board::get_rows(){
        return this->rows;
    }

    int Board::get_cols(){
        return this->cols;
    }

}

int main(void){


    // Testing default constructor
    Board *a = new Board();
    int a_rows = a->get_rows();
    int a_cols = a->get_cols();

    cout << "Board a default rows: " << a_rows << " default cols: " << a_cols << endl;

    // Testing two parameters constructor
    Board *b = new Board(3, 5);
    int b_rows = b->get_rows();
    int b_cols = b->get_cols();

    cout << "Board b rows: " << b_rows << " cols: " << b_cols << endl;

    if(1){
        // Testing single parameters constructor
        Board *c = new Board(10);
        int c_rows = c->get_rows();
        int c_cols = c->get_cols();

        cout << "Board c rows: " << c_rows << " cols: " << c_cols << endl;
    }
    

    delete a;
    delete b;

}

