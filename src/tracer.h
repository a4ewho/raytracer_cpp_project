#ifndef TRACER_H
#define TRACER_H

#include <vector>
#include <cstdint>
#include "Scene.h"
#include "Camera.h"
#include "Materials/Material.h"

const int MAX_DEPTH = 4;
const double OFFSET_EPSILON = 1e-4;

class Tracer {
public:
    Tracer(const Camera& camera, const Scene& scene);
    
    // Рендер в линейный RGB (float 0..1), затем гамма-коррекция и сохранение в uint8_t
    void render(std::vector<uint8_t>& output) const;

private:
    const Camera& m_camera;
    const Scene& m_scene;
    
    // Найти ближайшую фигуру, пересечённую лучом
    std::optional<std::pair<const Figure*, HitRecord>> findClosest(const Ray& ray) const;
    
    // Проверка тени: есть ли фигура между point и light
    bool isInShadow(const Vector3& point, const Light& light) const;
    
    // Локальное освещение (ambient + diffuse + specular) для точки
    Vector3 computeLocalLighting(const Figure* figure, const HitRecord& hit, const Vector3& viewDir) const;
    
    // Рекурсивная трассировка
    Vector3 traceRay(const Ray& ray, int depth) const;
    
    // Цвет фона (градиент по Y)
    Vector3 getBackgroundColor(const Ray& ray) const;
};

#endif