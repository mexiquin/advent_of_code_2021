// includes
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

typedef string int_str;

// declarations

/**
 * @brief Class abstraction for creating and handling a single 2d board vector
 *
 */
class Board
{
private:
    vector<int> cells_to_pull;
    vector<vector<int>> board_matrix;

public:
    Board( vector<vector<int>> board_vec );

    void get_cells_to_pull( string infile );
    void populate_matrix( string infile );
    void add_row( int_str row_str );
    void add_row( vector<int> row_str );
    bool is_empty( );
};

Board::Board( vector<vector<int>> board_vec )
{
    this->board_matrix = board_vec;
}

void Board::add_row( int_str row_str )
{
    if ( !row_str.empty( ) )
    {
        this->board_matrix.push_back( str_to_intvec( row_str ) );
    }
    else
    {
        cout << "[INFO] Supplied string is empty" << endl;
    }
}

void Board::add_row( vector<int> row )
{
    if ( !row.empty( ) )
    {
        this->board_matrix.push_back( row );
    }
    else
    {
        cout << "[INFO] Supplied vector is empty" << endl;
    }
}

bool Board::is_empty( )
{
    if ( board_matrix.empty( ) )
    {
        return true;
    }

    return false;
}

/**
 * @brief Class abstraction for handling multiple boards grouped together
 *
 */
class BoardGroup
{
public:
    vector<Board> boards;

    void add_board( Board new_board );
};

void BoardGroup::add_board( Board new_board )
{
    if ( !new_board.is_empty( ) )
    {
        this->boards.push_back( new_board );
    }
}



// functions
int main(int argc, char *argv[])
{
    // get next pull vector

    // get board vector

    // loop - for item in pull vector
        // for board in boards
            // if item in board
                // mark that item
    return 0;
}

