#ifndef LIGHT_H
#define LIGHT_H

#include <string>
#include "core/Vector3.h"

class Light {
public:
    // конструктор
    Light();
    Light(const std::string& name, const Vector3& position, 
          double intensity = 1.0, const Vector3& color = Vector3(1, 1, 1));

    const std::string& name() const { return m_name; }
    Vector3 position() const { return m_position; }
    double intensity() const { return m_intensity; }
    Vector3 color() const { return m_color; }
    
private:
    std::string m_name;
    Vector3 m_position;
    double m_intensity;
    Vector3 m_color;
};

#endif