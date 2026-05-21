#include "Scene.h"
#include "figures/Sphere.h"
#include "figures/Plane.h"
#include "Materials/material_library.h"
#include "Light.h"
#include <memory>

void setupScene3(Scene& scene) {
    scene.setBackgroundColor(Vector3(0.2, 0.2, 0.3));

    Material clearGlass("clear_glass", Vector3(0.95,0.98,1.0), 0.05, 0.05, 0.9, 256, 0.7);
    Material blueGlass ("blue_glass",  Vector3(0.2,0.5,0.9), 0.05, 0.1, 0.85, 200, 0.6);
    Material greenGlass("green_glass", Vector3(0.3,0.8,0.4), 0.05, 0.1, 0.85, 200, 0.6);

    auto sphere1 = std::make_shared<Sphere>(Vector3(-1.5, -0.2, -4.0), 0.7, clearGlass);
    auto sphere2 = std::make_shared<Sphere>(Vector3(1.5, -0.1, -4.5), 0.8, blueGlass);
    auto sphere3 = std::make_shared<Sphere>(Vector3(0.0, 0.1, -6.0), 0.9, greenGlass);
    auto ground  = std::make_shared<Plane>(Vector3(0, -1.0, 0), Vector3(0,1,0), MaterialLibrary::get("mirror"));

    scene.addFigure(sphere1);
    scene.addFigure(sphere2);
    scene.addFigure(sphere3);
    scene.addFigure(ground);

    Light soft("soft", Vector3(2.0, 5.0, -2.0), 1.5, Vector3(1,1,1));
    Light rim("rim", Vector3(-2.0, 3.0, -6.0), 1.0, Vector3(0.9,0.8,0.7));
    scene.addLight(soft);
    scene.addLight(rim);
}