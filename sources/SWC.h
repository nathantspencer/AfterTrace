#pragma once

#include "Vertex.h"

#include <map>
#include <stdio.h>

class SWC
{
    public:
        SWC();
        ~SWC();
    
    private:
        std::map<uint64_t, Vertex>  m_rowsToVertices;
        uint64_t                    m_greatestVertexId;
};
