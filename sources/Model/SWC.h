#pragma once

#include "Vertex.h"

#include <map>
#include <string>
#include <stdio.h>

class SWC
{
    public:
        SWC();
        ~SWC();
    
        std::map<uint64_t, std::string> GetRowsToComments();
        std::map<uint64_t, Vertex>      GetRowsToVertices();
        uint64_t                        GetGreatestVertexId();

        void                            SetRowsToComments(std::map<uint64_t, std::string> rowsToComments);
        void                            SetRowsToVertices(std::map<uint64_t, Vertex> rowsToVertices);
        void                            SetGreatestVertexId(uint64_t greatestVertexId);
    
    private:
        std::map<uint64_t, std::string> m_rowsToComments;
        std::map<uint64_t, Vertex>      m_rowsToVertices;
        uint64_t                        m_greatestVertexId;
};
