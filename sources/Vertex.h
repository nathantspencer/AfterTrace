/**
     
*/

#pragma once

#include <stdio.h>
#include <vector>
#include <glm/vec3.hpp>

class Vertex
{
    public:
        enum Type
        {
            UNDEFINED = 0,
            SOMA = 1,
            AXON = 2,
            DENDRITE = 3,
            APICAL_DENDRITE = 4,
            FORK_POINT = 5,
            END_POINT = 6,
            CUSTOM = 7
        };
    
        Vertex();
        Vertex(uint64_t id,  Type type, glm::vec3 position,  float radius, int64_t parentId);
    
        ~Vertex();
        
        uint64_t    GetId();
        Type         GetType();
        float       GetRadius();
        glm::vec3   GetPosition();
        int64_t     GetParentId();
    
        void        SetId(uint64_t id);
        void        SetParentId(int64_t parentId);
        void        SetRadius(float radius);
        void        SetPosition(glm::vec3 position);
    
    
    private:
        uint64_t    m_id;
        int64_t     m_parentId;
        float       m_radius;
        glm::vec3   m_position;
};
