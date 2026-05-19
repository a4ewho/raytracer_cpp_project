#ifndef RAY_HPP
#define RAY_HPP

#include "Vector3.h"

class Ray {
public:
    // конструктор
    Ray();
    Ray(const Vector3& origin, const Vector3& direction);

    Vector3 origin() const { return m_origin; }
    Vector3 direction() const { return m_direction; }

    void setOrigin(const Vector3& origin) { m_origin = origin; }
    void setDirection(const Vector3& direction) { m_direction = direction; }
    
    // получить точку на луче: origin + direction * t
    Vector3 at(double t) const;
    
private:
    Vector3 m_origin;
    Vector3 m_direction;
};

#endif // RAY_HPP