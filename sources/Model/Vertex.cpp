#include "Vertex.h"

Vertex::Vertex() :
    m_id(-1),
    m_type(UNDEFINED),
    m_position(glm::vec3()),
    m_radius(0.0f),
    m_parentId(-1)
{
}

Vertex::Vertex(uint64_t id, Type type, glm::vec3 position, float radius, int64_t parentId) :
    m_id(id),
    m_type(type),
    m_position(position),
    m_radius(radius),
    m_parentId(parentId)
{
}

Vertex::~Vertex()
{
}

uint64_t Vertex::GetId() const
{
    return m_id;
}

Vertex::Type Vertex::GetType() const
{
    return m_type;
}

int64_t Vertex::GetParentId() const
{
    return m_parentId;
}

float Vertex::GetRadius() const
{
    return m_radius;
}

glm::vec3 Vertex::GetPosition() const
{
    return m_position;
}

void Vertex::SetId(uint64_t id)
{
    m_id = id;
}

void Vertex::SetParentId(int64_t parentId)
{
    m_parentId = parentId;
}

void Vertex::SetRadius(float radius)
{
    m_radius = radius;
}

void Vertex::SetPosition(glm::vec3 position)
{
    m_position = position;
}
