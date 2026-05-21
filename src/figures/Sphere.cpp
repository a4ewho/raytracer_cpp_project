#include "Sphere.h"
#include <cmath>
#include <algorithm>

Sphere::Sphere() : m_center(), m_radius(1.0), m_material() {}

Sphere::Sphere(const Vector3& center, double radius, const Material& material)
    : m_center(center), m_radius(radius), m_material(material) {}

std::optional<HitRecord> Sphere::hit(const Ray& ray) const {
    // вектор от центра сферы до начала луча
    Vector3 oc = ray.origin() - m_center;
    
    // коэффициенты квадратного уравнения: a*t^2 + b*t + c = 0
    double a = dot(ray.direction(), ray.direction());
    double b = 2.0 * dot(oc, ray.direction());
    double c = dot(oc, oc) - m_radius * m_radius;
    
    double discriminant = b * b - 4 * a * c;
    
    if (discriminant < 0) {
        return std::nullopt;  // нет пересечений
    }
    
    double sqrt_d = std::sqrt(discriminant);
    
    // ищем наименьший положительный t
    double t1 = (-b - sqrt_d) / (2 * a);
    double t2 = (-b + sqrt_d) / (2 * a);
    
    double t = -1.0;
    if (t1 > 0 && t2 > 0) {
        t = std::min(t1, t2);  // берём ближайшее
    } else if (t1 > 0) {
        t = t1;
    } else if (t2 > 0) {
        t = t2;
    } else {
        return std::nullopt;  // оба пересечения позади луча (отриц)
    }
    
    // вычисляем точку пересечения
    Vector3 point = ray.at(t);
    
    // нормаль в точке пересечения (от центра сферы к точке)
    Vector3 normal = (point - m_center).normalized();
    
    return HitRecord{t, point, normal};
}