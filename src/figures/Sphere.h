#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Figure.h"

class Sphere : public Figure {
public:
    // конструктор
    Sphere();
    Sphere(const Vector3& center, double radius, const Material& material = Material());

    Vector3 center() const { return m_center; }
    double radius() const { return m_radius; }

    void setCenter(const Vector3& center) { m_center = center; }
    void setRadius(double radius) { m_radius = radius; }

    std::optional<HitRecord> hit(const Ray& ray) const override;
    std::string name() const override { return "Sphere"; }
    Material material() const override { return m_material; }
    
private:
    Vector3 m_center;
    double m_radius;
    Material m_material;
};

#endif // SPHERE_HPP