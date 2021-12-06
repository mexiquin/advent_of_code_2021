#if !defined(LINESTOARR)
#define LINESTOARR

#include<vector>
#include<string>
#include<fstream>
#include<iostream>

using namespace std;

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
std::vector<int> str_to_intvec( std::string victim_str )
{
    std::vector<int> temp_vec;

    for ( int i = 0; i < victim_str.size( ); i++ )
    {
        temp_vec.push_back( victim_str[ i ] - '0' );
    }
    return temp_vec;
}
vector<vector<int>> file_to_arr( string filename )
{
    vector<vector<int>> lines;
    std::vector<int> temp_vec;
    string line;

    ifstream input_file( filename );
    if ( !input_file.is_open( ) )
    {
        cerr << "Could not open file: " << filename << endl;
        return {};
    }

    while ( getline( input_file, line ) )
    {
        // convert line to char vector
        temp_vec = str_to_intvec( line );

        // place tuple into main vector
        lines.push_back( temp_vec );
    }

    return lines;
}

#endif // LINESTOARR
