//
// AUTHOURS: Tal Zichlinsky
//
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
const int MARGIN = 1;

// Constants for getting new board sizes after board resize
const int ROWS = 0;
const int COLS = 1;

// Default char
const char EMPTY_SPACE = '_';

// This method gets location of requested action (read or post) and resizes the board if location is out of current board size
vector<unsigned int> resize_board(unsigned int row, unsigned int col, Direction dir, unsigned int len, vector< vector<char> > &b){


    // At what index message will end for horizontal and vertical message respectively
    unsigned int col_end_pos = col + len;
    unsigned int row_end_pos = row + len;

    unsigned int board_rows = b.size();
    unsigned int board_cols = b[MIN_SIZE].size();

    size_t diff = 0, old_size = 0;

    if(row >= board_rows){
        diff = (row-board_rows) + 1;
        old_size = board_rows;

        board_rows += diff + MARGIN;

        // Resizing our board row number and adding margins. For loop fills each row with an empty space charecter
        b.resize(board_rows);
        for(size_t i = old_size; i < board_rows; i++){
            b[i].resize(board_cols, EMPTY_SPACE);
        }
        
    }

    if(col >= board_cols){
        diff = static_cast<size_t>(col_end_pos - board_cols);

        board_cols += diff + MARGIN;

        // Resizing all rows in this board to fit size of new meassage and adding margins
        for (unsigned int i = 0; i < board_rows; i++)
        {
            b[i].resize(board_cols, EMPTY_SPACE);
        }
    }

    // If message will not fit in this board vertically
    if (row_end_pos >= board_rows && dir == Direction::Vertical)
    {
        diff = static_cast<size_t>(row_end_pos - board_rows) + 1;

        old_size = board_rows;
        board_rows += diff + MARGIN;

        // Resizing our board row number and adding margins. For loop fills each row with an empty space charecter
        b.resize(board_rows);
        for(size_t i = old_size; i < board_rows; i++){
            b[i].resize(board_cols, EMPTY_SPACE);
        }
    }

    // If message will not fit in this board horizontally
    if (col_end_pos >= board_cols && dir == Direction::Horizontal)
    {
        diff = static_cast<size_t>(col_end_pos - board_cols);

        board_cols += diff + MARGIN;

        // Resizing all rows in this board to fit size of new meassage and adding margins
        for (unsigned int i = 0; i < board_rows; i++)
        {
            b[i].resize(board_cols, EMPTY_SPACE);
        }   
    }

    // New size for this board
    vector<unsigned int> new_size {board_rows, board_cols};
    return new_size;
}

namespace ariel
{

    // Default constructor
    Board::Board()
    {
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

        // Initializing vector with number of rows
        board.resize(rows);

        // Initializing each row of the vector with number of columns and the empty space char
        for (unsigned int i = 0; i < this->rows; i++)
        {
            board[i].resize(cols, EMPTY_SPACE);
        }
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

        // Initializing vector with number of rows
        board.resize(rows);

        // Initializing each row of the vector with number of columns and the empty space char
        for (unsigned int i = 0; i < this->rows; i++)
        {
            board[i].resize(cols, EMPTY_SPACE);
        }
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

        this->rows = new_size[ROWS];
        this->cols = new_size[COLS];

        if (dir == Direction::Horizontal)
        {
            // Posting message
            for (unsigned int i = 0; i < len; i++)
            {
                this->board[row][col + i] = msg[i];
            }
        }

        else
        {

            // Posting message
            for (unsigned int i = 0; i < len; i++)
            {
                this->board[row + i][col] = msg[i];
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

        // The string to return
        string msg;

        // Retrieving string from board
        if (dir == Direction::Horizontal)
        {
            for (unsigned int i = 0; i < len; i++)
            {
                msg += this->board[row][col + i];
            }
        }
        else
        {
            for (unsigned int i = 0; i < len; i++)
            {
                msg += this->board[row + i][col];
            }
        }
        return msg;
    }

    // This method will print out the entire message board
    void Board::show()
    {
        cout << endl;
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

    unsigned int Board::get_rows() const
    {
        return this->rows;
    }

    unsigned int Board::get_cols() const
    {
        return this->cols;
    }

}

