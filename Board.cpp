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

// Default and minimal size for a message board
const int DEFAULT_SIZE = 10;
const int MIN_SIZE = 1;

// Margins of messageboard
const int MARGIN = 3;

const char EMPTY_SPACE = '_';

void resize_board(unsigned int row, unsigned int col, Direction dir, string msg, Board &b){

    // Length of message
    unsigned int len = msg.size();

    // At what index message will end for horizontal and vertical message respectively
    unsigned int col_end_pos = col + len;
    unsigned int row_end_pos = row + len;

    // Marking directions for shorter access later
    int horiz = (dir == Direction::Horizontal);
    int vert = (dir == Direction::Vertical);

    // If message will not fit in this board vertically
    if (vert && row_end_pos >= b.get_rows())
    {

        // How bigger do we need our board to be
        size_t diff = static_cast<size_t>(row_end_pos - b.get_rows());

        size_t new_size = diff + MARGIN;

        // Resizing our board row number and adding margins
        b.board.resize(new_size);
    }

    // If message will not fit in this board horizontally
    if (horiz && col_end_pos >= b.get_cols())
    {

        // How bigger do we need our board to be
        size_t diff = static_cast<size_t>(col_end_pos - b.get_cols());

        size_t new_size = diff + MARGIN;

        // Resizing all rows in this board to fit size of new meassage and adding margins
        for (unsigned int i = 0; i < b.get_rows(); i++)
        {
            board[i].resize(new_size, EMPTY_SPACE);
        }
    }

}

// Default constructor
Board::Board()
{

    // No size is given as parameter so initializing to default size
    rows = DEFAULT_SIZE;
    cols = DEFAULT_SIZE;

    // Initializing vector with number of rows
    board.resize(rows);

    // Initializing each row of the vector with number of columns and the empty space char
    for (unsigned int i = 0; i < this->rows; i++)
    {
        board[i].resize(cols, EMPTY_SPACE);
    }
}

// Two parameter constructor
Board::Board(unsigned int rows, unsigned int cols)
{

    if (rows < MIN_SIZE)
    {
        throw invalid_argument("Invalid input: " + to_string(rows));
    }

    if (cols < MIN_SIZE)
    {
        throw invalid_argument("Invalid input: " + to_string(cols));
    }

    this->rows = rows;
    this->cols = cols;
}

// Single parameter constructor
Board::Board(unsigned int size)
{

    if (size < MIN_SIZE)
    {
        throw invalid_argument("Invalid input: " + to_string(rows));
    }

    this->rows = size;
    this->cols = size;
}

// Destructor
Board::~Board() {}

// This method will get row, column, direction and a message as parameters and posts the message in the
// appropriate location and diraction in this message board
int Board::post(unsigned int row, unsigned int col, Direction dir, string msg)
{

    // Length of message
    unsigned int len = msg.size();

    resize_board(row, col, dir, msg, *this);

    

    return 0;
}

// This method get row, column, direction and length of a message as parameters and returns the message in the
// appropriate location and diraction in this message board
string Board::read(unsigned int row, unsigned int col, Direction dir, unsigned int len)
{
    return " ";
}

// This message will print out the entire message board
void Board::show()
{

    for (size_t i = 0; i < this->rows; i++)
    {
        for (size_t j = 0; j < this->cols; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }

    cout << endl;
}

unsigned int Board::get_rows()
{
    return this->rows;
}

unsigned int Board::get_cols()
{
    return this->cols;
}

int main(void){


    // Testing default constructor

    Board *a = new Board();
    // unsigned int a_rows = a->get_rows();
    // unsigned int a_cols = a->get_cols();

    // cout << "Board a default rows: " << a_rows << " default cols: " << a_cols << endl;

    // Testing two parameters constructor
    
    // Board *b = new Board(3, 5);
    // unsigned int b_rows = b->get_rows();
    // unsigned int b_cols = b->get_cols();

    // cout << "Board b rows: " << b_rows << " cols: " << b_cols << endl;

    // if(1){
    //     // Testing single parameters constructor
    //     Board c(10);
    //     unsigned int c_rows = c.get_rows();
    //     unsigned int c_cols = c.get_cols();

    //     cout << "Board c rows: " << c_rows << " cols: " << c_cols << endl;
    // }
    

    // delete a;
    // delete b;    

    a->show();
    a->post(5, 5, Direction::Vertical, "Hello World");
    return 0;
}

