#pragma once

#include "Vertex.h"

#include <vector>
#include <string>
#include <stdio.h>

/*! Data model for representation of a `.swc` file.
 *
 *  Each vertex in a graph is represented by an instance of this class.
 */
class SWC
{
    public:
    
        /*! The constructor for `SWC`.
         *
         *  An `SWC` constructed in this way contains no vertices or comments. It can be populated by
         *  parsing data from an `.swc` file using an instance of `Parser`.
         */
        SWC();
    
        /*! The destructor for `SWC`.
         */
        ~SWC();
    
        std::vector<std::string>    GetComments() const;
        std::vector<Vertex>         GetVertices() const;

        void    SetComments(std::vector<std::string> comments);
        void    SetVertices(std::vector<Vertex> vertices);
    
    private:
    
        std::vector<std::string>    m_comments;
        std::vector<Vertex>         m_vertices;
};
