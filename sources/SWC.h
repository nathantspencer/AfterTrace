#pragma once

#include <stdio.h>
#include <vector>
#include <glm/vec3.hpp>

class SWC
{
public:
    struct Vertex
    {
        uint64_t id;
        float radius;
        glm::vec3 position;
        uint64_t parentId;
    };
    
private:
    std::vector<Vertex> vertices;
};
