#ifndef CAMERA_H
#define CAMERA_H

#include "core/Vector3.h"
#include "core/Ray.h"

class Camera {
public:
    Camera(const Vector3& position, const Vector3& lookAt, const Vector3& up,
           double fov, int width, int height);
    
    Ray getRay(int x, int y) const;   // x = 0..width-1, y = 0..height-1

private:
    Vector3 m_origin;
    Vector3 m_lowerLeftCorner;
    Vector3 m_horizontal;
    Vector3 m_vertical;
    int m_width, m_height;
};

#endif