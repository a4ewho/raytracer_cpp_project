#include "Ray.h"

Ray::Ray() : m_origin(), m_direction() {}

Ray::Ray(const Vector3& origin, const Vector3& direction)
    : m_origin(origin), m_direction(direction) {}

Vector3 Ray::at(double t) const {
    return m_origin + m_direction * t;
}