#pragma once

#include "Vertex.h"

#include <vector>
#include <string>
#include <stdio.h>

class SWC
{
    public:
        SWC();
        ~SWC();
    
        std::vector<std::string>    GetComments() const;
        std::vector<Vertex>         GetVertices() const;

        void                        SetComments(std::vector<std::string> comments);
        void                        SetVertices(std::vector<Vertex> vertices);
    
    private:
        std::vector<std::string>    m_comments;
        std::vector<Vertex>         m_vertices;
};
