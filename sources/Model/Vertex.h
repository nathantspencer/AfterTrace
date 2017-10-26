#pragma once

#include <stdio.h>
#include <glm/vec3.hpp>

class Vertex
{
    public:
    
        enum Type
        {
            UNDEFINED       = 0,
            SOMA            = 1,
            AXON            = 2,
            DENDRITE        = 3,
            APICAL_DENDRITE = 4,
            FORK_POINT      = 5,
            END_POINT       = 6,
            CUSTOM          = 7,
            NUMBER_OF_TYPES = CUSTOM
        };
    
        Vertex();
        Vertex(uint64_t id,  Type type, glm::vec3 position,  float radius, int64_t parentId);
        ~Vertex();
        
        uint64_t    GetId() const;
        Type        GetType() const;
        float       GetRadius() const;
        glm::vec3   GetPosition() const;
        int64_t     GetParentId() const;
    
        void    SetId(uint64_t id);
        void    SetParentId(int64_t parentId);
        void    SetRadius(float radius);
        void    SetPosition(glm::vec3 position);
    
    private:
    
        uint64_t    m_id;
        Type        m_type;
        glm::vec3   m_position;
        float       m_radius;
        int64_t     m_parentId;
};
