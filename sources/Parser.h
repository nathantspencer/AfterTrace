#pragma once

#include "SWC.h"

class Parser
{
    public:
        Parser();
        ~Parser();
    
        bool        ParseSWC(std::string path, SWC& result);
    
    private:
        bool        GrabCommentLine(std::string& result);
        bool        GrabType(Vertex::Type& result);
        bool        GrabFloat(float& result);
        bool        GrabInt64(int64_t& result);
        bool        GrabUint64(uint64_t& result);
    
        bool        DiscardSpacing();
        bool        DiscardLineEnding();
        bool        DiscardFileEnding();
        bool        DiscardCommentLine();
    
        const char* m_content;
};
