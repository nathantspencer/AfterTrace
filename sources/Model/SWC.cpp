#include "SWC.h"

SWC::SWC() :
    m_comments(std::vector<std::string>()),
    m_vertices(std::vector<Vertex>())
{
}

SWC::~SWC()
{
}

std::vector<std::string> SWC::GetComments() const
{
    return m_comments;
}

std::vector<Vertex> SWC::GetVertices() const
{
    return m_vertices;
}

void SWC::SetComments(std::vector<std::string> comments)
{
    m_comments = comments;
}

void SWC::SetVertices(std::vector<Vertex> vertices)
{
    m_vertices = vertices;
}
