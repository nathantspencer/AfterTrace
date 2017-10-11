#pragma once

#include <stdio.h>
#include <vector>
#include <glm/vec3.hpp>

class Vertex
{
    public:
        Vertex();
        Vertex(int64_t id, int64_t parentId, float radius, glm::vec3 position);
    
        ~Vertex();
        
        int64_t     GetId();
        int64_t     GetParentId();
        float       GetRadius();
        glm::vec3   GetPosition();
    
        void        SetId(int64_t id);
        void        SetParentId(int64_t parentId);
        void        SetRadius(float radius);
        void        SetPosition(glm::vec3 position);
        
        
    private:
        int64_t     m_id;
        int64_t     m_parentId;
        float       m_radius;
        glm::vec3   m_position;
};
