#if !defined(LINESTOARR)
#define LINESTOARR

#include<vector>
#include<string>
#include<fstream>
#include<tuple>
#include<iostream>

using namespace std;


// string alias, denotes string destined to be converted to vec<int>
typedef string int_str;

vector<string> lines_to_str_arr( string filename )
{
    vector<string> lines;
    string line;

    ifstream input_file( filename );
    if ( !input_file.is_open( ) )
    {
        cerr << "Could not open file: " << filename << endl;
        return {};
    }

    while ( getline( input_file, line ) )
    {
        lines.push_back( line );
    }

    return lines;
}

// TODO day 4 - 2D int array load
vector<int> str_to_intvec( int_str victim_str )
{
    vector<int> temp_vec;

    for ( int i = 0; i < victim_str.size( ); i++ )
    {
        temp_vec.push_back( victim_str[ i ] - '0' );
    }
    return temp_vec;
}
tuple<vector<int>, vector<vector<vector<int>>>> file_to_arr( string filename )
{
    vector<vector<vector<int>>> boards;
    vector<vector<int>> board;
    vector<int> pull_nums;

    vector<int> temp_vec;
    string line;
    int iter=0;

    ifstream input_file( filename );
    if ( !input_file.is_open( ) )
    {
        cerr << "Could not open file: " << filename << endl;
        exit( 1 );
    }

    // get first line for pull order
    if ( getline( input_file, line ) )
    {
        pull_nums = str_to_intvec( line );
    }
    else
    {
        cout << "Error reading first line of file" << endl;
        exit( 1 );
    }

    // TODO - subsequent lines (blank-newline separated) are 2d grids
    while ( getline( input_file, line ) )
    {
        // Populate temp lvl 2 vector (2d)
            // if current line has stuff in it
            if(!line.empty()){
                // put that stuff into array lvl 2
                board.push_back(str_to_intvec(line));
    }
            // else, increment and start populating lvl 3 (master) vector
    }

    return make_tuple(pull_nums, boards);
}

#endif // LINESTOARR
