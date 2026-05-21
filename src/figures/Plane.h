#ifndef PLANE_H
#define PLANE_H

#include "Figure.h"

class Plane : public Figure {
public:
    Plane();
    Plane(const Vector3& point, const Vector3& normal, const Material& material = Material());

    Vector3 point() const { return m_point; }
    Vector3 normal() const { return m_normal; }

    std::optional<HitRecord> hit(const Ray& ray) const override;
    std::string name() const override { return "Plane"; }
    Material material() const override { return m_material; }

private:
    Vector3 m_point;   // точка на плоскости
    Vector3 m_normal;  // нормаль плоскости (единичная)
    Material m_material; // материал
};

#endif // PLANE_H