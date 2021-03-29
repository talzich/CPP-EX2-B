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
const int MARGIN = 5;

const int ROWS = 0;
const int COLS = 1;

const char EMPTY_SPACE = '_';

vector<unsigned int> resize_board(unsigned int row, unsigned int col, Direction dir, unsigned int len, vector< vector<char> > &b){


    // At what index message will end for horizontal and vertical message respectively
    unsigned int col_end_pos = col + len;
    unsigned int row_end_pos = row + len;

    unsigned int board_rows = b.size();
    unsigned int board_cols = b[MIN_SIZE].size();

    // Marking  for shorter access later
    int horiz = (dir == Direction::Horizontal);
    int vert = (dir == Direction::Vertical);

    // If message will not fit in this board vertically
    if (row_end_pos >= board_rows)
    {
        // How bigger do we need our board to be
        size_t diff = static_cast<size_t>(row_end_pos - board_rows);

        size_t old_size = board_rows;
        board_rows += diff + MARGIN;

        // Resizing our board row number and adding margins
        b.resize(board_rows);

        for(size_t i = old_size; i < board_rows; i++){
            b[i].resize(board_cols, EMPTY_SPACE);
        }
    }

    // If message will not fit in this board horizontally
    if (col_end_pos >= board_cols)
    {

        // How bigger do we need our board to be
        size_t diff = static_cast<size_t>(col_end_pos - board_cols);

        board_cols += diff + MARGIN;

        // Resizing all rows in this board to fit size of new meassage and adding margins
        for (unsigned int i = 0; i < board_rows; i++)
        {
            b[i].resize(board_cols, EMPTY_SPACE);
        }
    }

    vector<unsigned int> new_size {board_rows, board_cols};
    return new_size;

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

    // Resizing the board, if necessary
    vector<unsigned int> new_size = resize_board(row, col, dir, len, this->board);
    
    // Updating board size
    this->rows = new_size[ROWS];
    this->cols = new_size[COLS];
    
    if(dir == Direction::Horizontal){
        // Posting message
        for(unsigned int i = 0; i < len; i++){
            this->board[row][col+i] = msg[i];
        }
    }

    else{
        // Posting message
        for(unsigned int i = 0; i < len; i++){
            this->board[row+i][col] = msg[i];
        }
    }
    return 0;
}

// This method get row, column, direction and length of a message as parameters and returns the message in the
// appropriate location and diraction in this message board
string Board::read(unsigned int row, unsigned int col, Direction dir, unsigned int len)
{

    // Resizing the board, if necessary
    vector<unsigned int> new_size = resize_board(row, col, dir, len, this->board);

    // Updating board size
    this->rows = new_size[ROWS];
    this->cols = new_size[COLS];

    string msg;

    
    if(dir == Direction::Horizontal){
        for(unsigned int i = 0; i < len; i++){
            msg += this->board[row][col+i];
        }
        return msg;
    }

    
    for(unsigned int i = 0; i < len; i++){
        msg += this->board[row+i][col];
    }
    return msg;
    
}

// This message will print out the entire message board
void Board::show()
{

    for (size_t i = 0; i < this->rows; i++)
    {
        cout << i << '\t';
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

// int main(void){

//     Board *a = new Board();   

//     a->show();
//     a->post(5, 5, Direction::Vertical, "Hello World");
//     a->show();

//     a->post(5, 5, Direction::Horizontal, "Hello World");
//     a->show();

//     a->post(3,5, Direction::Vertical, "Zich");
//     a->show();

//     cout << a->read(5, 5, Direction::Horizontal, 11) << endl;

//     cout << a->read(34, 100, Direction::Vertical, 5) << endl;

//     return 0;
// }

