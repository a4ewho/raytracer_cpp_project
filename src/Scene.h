#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>
#include "figures/Figure.h"
#include "Light.h"

class Scene {
public:
    Scene();
    Scene(int width, int height);

    // добавление объектов
    void addFigure(std::shared_ptr<Figure> figure);
    void addLight(const Light& light);

    // удаление всех объектов
    void clearFigures();
    void clearLights();

    const std::vector<std::shared_ptr<Figure>>& figures() const { return m_figures; }
    const std::vector<Light>& lights() const { return m_lights; }

    int width() const { return m_width; }
    int height() const { return m_height; }

    Vector3 backgroundColor() const { return m_backgroundColor; }
    void setBackgroundColor(const Vector3& color) { m_backgroundColor = color; }

private:
    std::vector<std::shared_ptr<Figure>> m_figures;
    std::vector<Light> m_lights;
    int m_width;
    int m_height;
    Vector3 m_backgroundColor;
};

#endif