#pragma once

#include <Model/SWC.h>

class Writer
{
    public:
    
        Writer();
        ~Writer();
    
        bool    WriteSWC(const std::string& path, const SWC& swc);
    
    private:
    
};
