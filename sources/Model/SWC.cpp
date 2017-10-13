#include "SWC.h"

SWC::SWC() :
    m_rowsToComments(std::map<uint64_t, std::string>()),
    m_rowsToVertices(std::map<uint64_t, Vertex>()),
    m_greatestVertexId(-1)
{
}

SWC::~SWC()
{
}

std::map<uint64_t, std::string> SWC::GetRowsToComments()
{
    return m_rowsToComments;
}

std::map<uint64_t, Vertex> SWC::GetRowsToVertices()
{
    return m_rowsToVertices;
}

uint64_t SWC::GetGreatestVertexId()
{
    return m_greatestVertexId;
}

void SWC::SetRowsToComments(std::map<uint64_t, std::string> rowsToComments)
{
    m_rowsToComments = rowsToComments;
}

void SWC::SetRowsToVertices(std::map<uint64_t, Vertex> rowsToVertices)
{
    m_rowsToVertices = rowsToVertices;
}

void SWC::SetGreatestVertexId(uint64_t greatestVertexId)
{
    m_greatestVertexId = greatestVertexId;
}


