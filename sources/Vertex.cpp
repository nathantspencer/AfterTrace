#include "Vertex.h"

Vertex::Vertex() :
    m_id(-1),
    m_parentId(-1),
    m_radius(0.0f),
    m_position(glm::vec3())
{
}

Vertex::Vertex(int64_t id, int64_t parentId, float radius, glm::vec3 position) :
    m_id(id),
    m_parentId(parentId),
    m_radius(radius),
    m_position(position)
{
}

Vertex::~Vertex()
{
}

int64_t Vertex::GetId()
{
    return m_id;
}

int64_t Vertex::GetParentId()
{
    return m_parentId;
}

float Vertex::GetRadius()
{
    return m_radius;
}

glm::vec3 Vertex::GetPosition()
{
    return m_position;
};

void Vertex::SetId(int64_t id)
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
};
