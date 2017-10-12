#include "Parser.h"

#include <iostream>
#include <fstream>
#include <string>

SWC Parser::ParseSWC(std::string path)
{
    std::string line;
    std::ifstream myfile(path);
    
    if(!myfile.good())
    {
        std::cout << "WARNING: ParseSWC(path) could not open file at path" << '\n';
        return SWC();
    }
    
    std::cout << myfile.good();
    if (myfile.is_open())
    {
        while (getline(myfile,line))
        {
            std::cout << line << '\n';
        }
        myfile.close();
    }
    return SWC();
}
