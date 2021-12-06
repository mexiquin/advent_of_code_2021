#if !defined(LINESTOARR)
#define LINESTOARR

#include<vector>
#include<string>
#include<fstream>
#include<iostream>

std::vector<std::string> lines_to_arr( std::string filename )
{
    std::vector<std::string> lines;
    std::string line;

    std::ifstream input_file( filename );
    if ( !input_file.is_open( ) )
    {
        std::cerr << "Could not open file: " << filename << std::endl;
        return {};
    }

    while ( getline( input_file, line ) )
    {
        lines.push_back( line );
    }

    return lines;
}

#endif // LINESTOARR
