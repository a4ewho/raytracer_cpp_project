#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include "core/Vector3.h"

class Material {
public:
    // Конструктор
    Material();
    Material(const std::string& name, const Vector3& color,
             double ka = 0.2, double kd = 0.7, double ks = 0.5, double shininess = 32, double kr = 0.0);

    const std::string& name() const { return m_name; }
    Vector3 color() const { return m_color; }
    double ka() const { return m_ka; }      // коэффициент ambient (базовое освещение)
    double kd() const { return m_kd; }      // коэффициент diffuse (зависит от угла падения)
    double ks() const { return m_ks; }      // коэффициент specular (зеркальный блик)
    double shininess() const { return m_shininess; }
    double reflectionCoeff() const { return m_kr; }
    
private:
    std::string m_name;      // имя материала
    Vector3 m_color;         // цвет (R, G, B) в диапазоне 0..1
    double m_ka;             // ambient коэффициент (0..1)
    double m_kd;             // diffuse коэффициент (0..1)
    double m_ks;             // specular коэффициент (0..1)
    double m_shininess;      // блеск (чем выше, тем ярче блик)
    double m_kr;             // reflection coefficient (0 = no reflection)
};

#endif