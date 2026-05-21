#include "Camera.h"
#include <cmath>
const double PI = 3.141592653589793;

Camera::Camera(const Vector3& position, const Vector3& lookAt, const Vector3& up,
               double fov, int width, int height)
    : m_origin(position), m_width(width), m_height(height)
{
    double aspect = static_cast<double>(width) / height;
    double theta = fov * PI / 180.0;
    double halfHeight = std::tan(theta / 2.0);
    double halfWidth = aspect * halfHeight;
    
    Vector3 w = (position - lookAt).normalized();   // forward
    Vector3 u = cross(up, w).normalized();          // right — используем свободную функцию cross
    Vector3 v = cross(w, u).normalized();           // corrected up
    
    m_lowerLeftCorner = m_origin - halfWidth * u - halfHeight * v - w;
    m_horizontal = 2.0 * halfWidth * u;
    m_vertical   = 2.0 * halfHeight * v;
}

Ray Camera::getRay(int x, int y) const {
    double u = (x + 0.5) / m_width;
    double v = (m_height - y - 0.5) / m_height;   // <- исправлено
    Vector3 direction = m_lowerLeftCorner + u * m_horizontal + v * m_vertical - m_origin;
    direction = direction.normalized();
    return Ray(m_origin, direction);
}