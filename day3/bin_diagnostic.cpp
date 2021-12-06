// includes
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <tuple>
#include <omp.h>
#include <math.h>

// declarations
std::vector<std::vector<int>> file_to_arr( std::string filename );
std::tuple<std::vector<int>, std::vector<int>> rate_calc( std::vector<std::vector<int>> file_lines );


// calculate gamma rate (most frequent bit per column)
std::tuple<std::vector<int>, std::vector<int>> rate_calc(std::vector<std::vector<int>> main_vec )
{
    std::vector<int> gamma;
    std::vector<int> epsilon;
    int index;

    // for number of columns
    for ( index = 0; index < main_vec[ index ].size( ); index++ )
    {
        int num0 = 0, num1 = 0;

        // compare all chars in current index
        for ( auto main_item : main_vec )
        {
            switch ( main_item[ index ] )
            {
            case 0:
                num0++;
                break;

            case 1:
                num1++;
                break;
            }
        }

        // append most frequent char to val
        if ( num0 > num1 )
        {
            gamma.push_back( 0 );
            epsilon.push_back( 1 );
        }
        else
        {
            gamma.push_back( 1 );
            epsilon.push_back( 0 );
        }
    }

    return std::make_tuple( gamma, epsilon );
}


// functions

std::vector<int> str_to_intvec( std::string victim_str )
{
    std::vector<int> temp_vec;

    for ( int i = 0; i < victim_str.size( ); i++ )
    {
        temp_vec.push_back( victim_str[ i ] - '0' );
    }
    return temp_vec;
}

std::vector<std::vector<int>> file_to_arr( std::string filename )
{
    std::vector<std::vector<int>> lines;
    std::vector<int> temp_vec;
    std::string line;

    std::ifstream input_file( filename );
    if ( !input_file.is_open( ) )
    {
        std::cerr << "Could not open file: " << filename << std::endl;
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

/**
 * @brief converts vector of ints (representing binary) into a decimal int
 *
 * @param binary_num vector array representing binary integer
 * @return int converted decimal value
 */
int bin_to_int( std::vector<int> binary_num )
{
    int dec_num = 0;

    for ( int iter = 0; iter < binary_num.size( ); iter++ )
    {
        if ( binary_num[ iter ] > 1 || binary_num[ iter ] < 0 )
        {
            return -1;
        }

        dec_num += ( binary_num[ iter ] * pow( 2, ( binary_num.size( ) - 1 ) - iter ) );
    }

    return dec_num;
}

int main( int argc, char const* argv [ ] )
{

    // variables
    std::vector<int> gamma;
    std::vector<int> epsilon;

    int gamma_dec;
    int epsilon_dec;

    std::vector<std::vector<int>> main_vector = file_to_arr( argv[ 1 ] );

    // get gamma and epsilon
    tie( gamma, epsilon ) = rate_calc( main_vector );

    // convert to int
    gamma_dec = bin_to_int( gamma );
    epsilon_dec = bin_to_int( epsilon );

    // multiply gamma * epsilon int
    std::cout << "Gamma val: " << gamma_dec << "\n" << "Epsilon val: " << epsilon_dec << "\n" << std::endl;
    std::cout << "multiplied gamma-epsilon: " << gamma_dec * epsilon_dec << std::endl;

    return 0;
}


