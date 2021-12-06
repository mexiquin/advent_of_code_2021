// includes
#include <vector>
#include <iostream>
#include <fstream>
#include <tuple>

// declarations
#define STR_EQ 0

class Submarine
{
public:
    int depth;
    int h_position;
    int aim;

    Submarine( int depth, int h_pos, int aim );

    void forward( int val );
    void down( int val );
    void up( int val );
};

Submarine::Submarine( int depth, int h_pos, int aim )
{
    this->depth = depth;
    this->h_position = h_pos;
    this->aim = aim;
}

void Submarine::forward( int val )
{
    this->h_position+=val;
    this->depth+=val*this->aim;
}

void Submarine::down( int val )
{
    this->aim+=val;
}

void Submarine::up( int val )
{
    this->aim-=val;
}

std::tuple<std::string, int> extract_command( std::string command_str )
{
    // turn line into split tuple
    std::string delimiter = " ";
    std::string command;
    int val;
    size_t pos = command_str.find( delimiter );

    command = command_str.substr( 0, pos );
    val = std::stoi( command_str.substr( pos, pos + 1 ) );

    // convert to tuple
    std::tuple<std::string, int> cmd_tuple( command, val );
    return cmd_tuple;
}

// read file input to array
std::vector<std::tuple<std::string, int>> file_to_arr( std::string filename )
{
    std::vector<std::tuple<std::string, int>> lines;
    std::tuple<std::string, int> temp_tuple;
    std::string line;

    std::ifstream input_file( filename );
    if ( !input_file.is_open( ) )
    {
        std::cerr << "Could not open file: " << filename << std::endl;
        return {};
    }

    while ( getline( input_file, line ) )
    {

        // convert line to tuple
        temp_tuple = extract_command( line );

        // place tuple into main vector
        lines.push_back( temp_tuple );
    }

    return lines;
}

/**
 * @brief execute commands based on string commands
 *
 * @param cmd_list vector containing command/val tuples
 * @param sub submarine object to manipulate
 */
void interpret_commands( std::vector<std::tuple<std::string, int>> cmd_list, Submarine& sub )
{
    for ( auto iter : cmd_list )
    {
        std::string cmd = std::get<0>(iter);
        int val = std::get<1>(iter);

        if (cmd.compare( "forward" ) == STR_EQ )
        {
            sub.forward( val );
        }
        else if ( cmd.compare( "down" ) == STR_EQ )
        {
            sub.down( val );
        }
        else if ( cmd.compare( "up" ) == STR_EQ )
        {
            sub.up( val );
        }
    }
}


int main( int argc, char* argv [ ] )
{
    std::vector<std::tuple<std::string, int>> command_list = file_to_arr( argv[ 1 ] );
    Submarine santaSub( 0, 0, 0 );

    interpret_commands( command_list, santaSub );

    std::cout << "Depth result: " << santaSub.depth << "\n" << "Horizontal Position Result: " << santaSub.h_position << std::endl;

    std::cout << "Multiplication of the two values: " << santaSub.depth * santaSub.h_position << std::endl;

    return 0;
}





