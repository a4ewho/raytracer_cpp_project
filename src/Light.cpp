#include "Light.h"

// конструктор по умолчанию
Light::Light() 
    : m_name("light"), m_position(0, 0, 0), m_intensity(1.0), m_color(1, 1, 1) {}

Light::Light(const std::string& name, const Vector3& position, 
             double intensity, const Vector3& color)
    : m_name(name), m_position(position), m_intensity(intensity), m_color(color) {}