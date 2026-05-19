#include "Plane.h"
#include <cmath>

const double EPSILON = 1e-6;

Plane::Plane() : m_point(), m_normal(0, 1, 0) {}

Plane::Plane(const Vector3& point, const Vector3& normal)
    : m_point(point), m_normal(normal.normalized()) {}

std::optional<HitRecord> Plane::hit(const Ray& ray) const {
    double denom = dot(ray.direction(), m_normal);
    
    // луч параллелен плоскости
    if (std::abs(denom) < EPSILON) {
        return std::nullopt;
    }
    
    double t = dot(m_point - ray.origin(), m_normal) / denom;
    
    if (t < EPSILON) {
        return std::nullopt;  // пересечение позади
    }
    
    Vector3 point = ray.at(t);
    
    return HitRecord{t, point, m_normal};
}