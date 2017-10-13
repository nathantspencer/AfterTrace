#include "Writer.h"

#include <iostream>
#include <fstream>
#include <sstream>

Writer::Writer()
{
}

Writer::~Writer()
{
}

bool Writer::WriteSWC(const std::string& path, const SWC& swc)
{
    std::ofstream file(path, std::ios::binary);
    
    if (!file.is_open())
    {
        std::cout << "WARNING: WriteSWC() could not open file at " << path << '\n';
        return false;
    }
    
    std::stringstream writeStream;
    std::vector<std::string> comments = swc.GetComments();
    std::vector<Vertex> vertices = swc.GetVertices();

    for (std::string comment : comments)
    {
        writeStream << comment << '\n';
    }
    
    for(Vertex vertex : vertices)
    {
        std::string id = std::to_string(vertex.GetId());
        std::string type = std::to_string(int(vertex.GetType()));
        std::string x = std::to_string(vertex.GetPosition().x);
        std::string y = std::to_string(vertex.GetPosition().y);
        std::string z = std::to_string(vertex.GetPosition().z);
        std::string radius = std::to_string(vertex.GetRadius());
        std::string parentId = std::to_string(vertex.GetParentId());
        
        writeStream << id << '\t';
        writeStream << type << '\t';
        writeStream << x << '\t';
        writeStream << y << '\t';
        writeStream << z << '\t';
        writeStream << radius << '\t';
        writeStream << parentId << '\n';
    }
    
    file << writeStream.rdbuf();
    file.close();
    return true;
}
