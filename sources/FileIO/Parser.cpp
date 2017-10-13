#include "Parser.h"

#include <iostream>
#include <fstream>
#include <vector>

Parser::Parser()
{
}

Parser::~Parser()
{
}

bool Parser::ParseSWC(const std::string& path, SWC& result)
{
    std::string line;
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    if (!file.is_open())
    {
        std::cout << "WARNING: ParseSWC() could not open file at " << path << '\n';
        return false;
    }

    char* content = new char[static_cast<size_t>(size) + 1];
    file.read(content, size);
    content[size] = '\0';
    m_content = content;
    
    result = SWC();
    std::vector<Vertex> vertices;
    std::vector<std::string> comments;
    std::string comment;
    while (GrabCommentLine(comment))
    {
        comments.push_back(comment);
    }
    result.SetComments(comments);
    
    do
    {
        while (DiscardCommentLine());
        
        if (DiscardFileEnding())
        {
            break;
        }

        uint64_t id;
        DiscardSpacing();
        if (!GrabUint64(id))
        {
            delete[] content;
            return false;
        }
        
        Vertex::Type type;
        DiscardSpacing();
        if (!GrabType(type))
        {
            delete[] content;
            return false;
        }
        
        glm::vec3 position;
        for (int i = 0; i < 3; ++i)
        {
            DiscardSpacing();
            if (!GrabFloat(position[i]))
            {
                delete[] content;
                return false;
            }
        }
        
        float radius;
        DiscardSpacing();
        if (!GrabFloat(radius))
        {
            delete[] content;
            return false;
        }
        
        int64_t parentId;
        DiscardSpacing();
        if (!GrabInt64(parentId))
        {
            delete[] content;
            return false;
        }
        
        DiscardSpacing();
        Vertex vertex(id, type, position, radius, parentId);
        vertices.push_back(vertex);
    }
    while (DiscardLineEnding());
    
    if (!DiscardFileEnding())
    {
        delete[] content;
        return false;
    }
    
    result.SetVertices(vertices);
    delete[] content;
    file.close();
    
    return true;
}

bool Parser::GrabCommentLine(std::string &result)
{
    DiscardSpacing();
    std::vector<char> characters;
    if(*m_content == '#')
    {
        while(!DiscardLineEnding() && *m_content != '\0')
        {
            characters.push_back(*m_content);
            m_content++;
        }
        result = std::string(characters.begin(), characters.end());
        return true;
    }
    return false;
}

bool Parser::GrabType(Vertex::Type& result)
{
    char* endpoint;
    int integerType = strtol(m_content, &endpoint, 10);
    
    if(integerType > Vertex::Type::NUMBER_OF_TYPES)
    {
        return false;
    }
    
    result = Vertex::Type(integerType);
    if (endpoint > m_content)
    {
        m_content = endpoint;
        return true;
    }
    return false;
}

bool Parser::GrabFloat(float& result)
{
    char* endpoint;
    result = strtof(m_content, &endpoint);
    if (endpoint > m_content)
    {
        m_content = endpoint;
        return true;
    }
    return false;
}

bool Parser::GrabInt64(int64_t& result)
{
    char* endpoint;
    result = strtoll(m_content, &endpoint, 10);
    if (endpoint > m_content)
    {
        m_content = endpoint;
        return true;
    }
    return false;
}

bool Parser::GrabUint64(uint64_t& result)
{
    char* endpoint;
    result = strtoull(m_content, &endpoint, 10);
    if (endpoint > m_content)
    {
        m_content = endpoint;
        return true;
    }
    return false;
}

bool Parser::DiscardSpacing()
{
    bool spacingFound = false;
    while (*m_content == '\t' || *m_content == ' ')
    {
        spacingFound = true;
        m_content++;
    }
    return spacingFound;
}

bool Parser::DiscardLineEnding()
{
    bool lineEndingFound = false;
    if (*m_content == '\r')
    {
        lineEndingFound = true;
        m_content++;
    }
    if (*m_content == '\n')
    {
        lineEndingFound = true;
        m_content++;
    }
    return lineEndingFound;
}

bool Parser::DiscardFileEnding()
{
    return *m_content == '\0';
}

bool Parser::DiscardCommentLine()
{
    DiscardSpacing();
    if(*m_content == '#')
    {
        while(!DiscardLineEnding() && *m_content != '\0')
        {
            m_content++;
        }
        return true;
    }
    return false;
}
