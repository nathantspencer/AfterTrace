#pragma once

#include <stdio.h>
#include <glm/vec3.hpp>

/*! Data model for graph vertex information.
 *
 *  Each vertex in a graph is represented by an instance of this class.
 */
class Vertex
{
    public:
    
        /*! The type of the neuronal segment represented by a `Vertex`.
         */
        enum Type
        {
            UNDEFINED       = 0,
            SOMA            = 1,
            AXON            = 2,
            DENDRITE        = 3,
            APICAL_DENDRITE = 4,
            FORK_POINT      = 5,
            END_POINT       = 6,
            CUSTOM          = 7
        };
    
        /*! The default constructor for `Vertex`.
         *
         *  Creates a `Vertex` with default values. Note that an instance created in tis way cannot be used
         *  without setting at least the ID of the `Vertex` after the fact because this constructor
         *  assigns an impossible ID of -1.
         */
        Vertex();
    
        /*! The constructor for a `Vertex` with known attributes.
         *
         *  Creates a `Vertex` with the given ID, parent, type, position, and radius.
         *
         *  @param id a natural number ID to be assigned to the new `Vertex`
         *  @param type the type of the neuronal segment represented by the new `Vertex`
         *  @param position the 3-dimensional position of the new `Vertex`
         *  @param radius the radius to be assigned to the new `Vertex`
         *  @param parentId the natural number ID of the new `Vertex`'s parent, or -1 if the new `Vertex` is a root
         */
        Vertex(uint64_t id,  Type type, glm::vec3 position,  float radius, int64_t parentId);
    
        /* The deconstructor for `Vertex`.
         */
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
