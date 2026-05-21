#include "Material.h"

// конструктор по умолчанию (серый матовый материал)
Material::Material()
    : m_name("default"), m_color(1, 1, 1)
    , m_ka(0.2), m_kd(0.7), m_ks(0.5), m_shininess(32), m_kr(0.0) {}

// конструктор
Material::Material(const std::string& name, const Vector3& color,
                   double ka, double kd, double ks, double shininess, double kr)
    : m_name(name), m_color(color)
    , m_ka(ka), m_kd(kd), m_ks(ks), m_shininess(shininess), m_kr(kr) {}