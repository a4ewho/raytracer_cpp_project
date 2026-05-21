#include "Scene.h"

Scene::Scene() 
    : m_width(800), m_height(600), m_backgroundColor(0.1, 0.1, 0.2) {}

Scene::Scene(int width, int height) 
    : m_width(width), m_height(height), m_backgroundColor(0.1, 0.1, 0.2) {}

void Scene::addFigure(std::shared_ptr<Figure> figure) {
    m_figures.push_back(figure);
}

void Scene::addLight(const Light& light) {
    m_lights.push_back(light);
}

void Scene::clearFigures() {
    m_figures.clear();
}

void Scene::clearLights() {
    m_lights.clear();
}