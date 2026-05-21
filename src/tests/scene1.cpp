#include "Scene.h"
#include "figures/Sphere.h"
#include "figures/Plane.h"
#include "Materials/material_library.h"
#include "Light.h"
#include <memory>

void setupScene1(Scene& scene) {
    scene.setBackgroundColor(Vector3(0.8, 0.9, 1.0));

    const Material& glass   = MaterialLibrary::get("glass");
    const Material& gold    = MaterialLibrary::get("gold");
    const Material& plastic = MaterialLibrary::get("plastic");

    Material ground("ground", Vector3(0.55, 0.27, 0.07), 0.2, 0.7, 0.3, 32, 0.0);

    auto sphereGlass = std::make_shared<Sphere>(Vector3(-1.2, -0.2, -4.0), 0.8, glass);
    auto sphereGold  = std::make_shared<Sphere>(Vector3(1.5, -0.3, -5.0), 0.9, gold);
    auto sphereRed   = std::make_shared<Sphere>(Vector3(0.0, -0.5, -7.0), 0.7, plastic);
    auto planeGround = std::make_shared<Plane>(Vector3(0, -1.0, 0), Vector3(0, 1, 0), ground);

    scene.addFigure(sphereGlass);
    scene.addFigure(sphereGold);
    scene.addFigure(sphereRed);
    scene.addFigure(planeGround);

    Light sun("sun", Vector3(5.0, 8.0, -2.0), 1.8, Vector3(1,1,1));
    Light fill("fill", Vector3(-3.0, 2.0, -4.0), 0.5, Vector3(0.9,0.8,0.7));
    scene.addLight(sun);
    scene.addLight(fill);
}