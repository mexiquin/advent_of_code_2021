// imports
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// declarations
std::vector<int> file_to_arr( std::string filename );
std::vector<int> group_3_sums( std::vector<int> main_vec );
int num_increases( std::vector<int> group_vector );

// functions
int main( int argc, char* argv [ ] )
{

    int number_of_increases;

    // create new vector with data
    std::vector<int> data_vec = file_to_arr( argv[ 1 ] );

    // create new vector with sum data
    std::vector<int> group_vec = group_3_sums( data_vec );

    // parse new sum vector for increases
    number_of_increases = num_increases( group_vec );

    // print number of increases
    std::cout << "Number of increases: " << number_of_increases << std::endl;

    return EXIT_SUCCESS;
}


// read file input into array
std::vector<int> file_to_arr( std::string filename )
{
    std::vector<int> lines;
    std::string line;
    int line_int_conv;

    std::ifstream input_file( filename );
    if ( !input_file.is_open( ) )
    {
        std::cerr << "Could not open file: " << filename << std::endl;
        return {};
    }

    while ( getline( input_file, line ) )
    {
        line_int_conv = std::stoi( line );
        lines.push_back( line_int_conv );
    }

    return lines;
}

// get sum of groups of 3 elements and place them into new vector (stop grouping when iter+2== NULL)
std::vector<int> group_3_sums( std::vector<int> main_vec )
{
    int iter, sum;
    std::vector<int> group_vec;

    if ( !main_vec.empty( ) )
    {
        for ( iter = 2; iter < main_vec.size( ); iter++ )
        {
            sum = main_vec[ iter - 2 ] + main_vec[ iter - 1 ] + main_vec[ iter ];
            group_vec.push_back( sum );
        }
    }

    return group_vec;
}

// compare values in new vector same as before
int num_increases( std::vector<int> group_vector )
{
    int iter, number_increase = 0;
    for ( iter = 1; iter < group_vector.size( ); iter++ )
    {
        if ( group_vector[ iter ] > group_vector[ iter - 1 ] )
        {
            number_increase++;
        }
    }

    return number_increase;
}
