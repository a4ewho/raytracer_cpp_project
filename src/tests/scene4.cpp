#include "Scene.h"
#include "figures/Sphere.h"
#include "figures/Plane.h"
#include "Materials/material_library.h"
#include "Light.h"
#include <memory>

void setupScene4(Scene& scene) {
    scene.setBackgroundColor(Vector3(0.0, 0.0, 0.0)); // чёрный фон не отражается

    const Material& mirror = MaterialLibrary::get("mirror");
    Material goldRich("gold_rich", Vector3(1.0, 0.85, 0.4), 0.15, 0.6, 0.5, 120, 0.35);

    auto floor = std::make_shared<Plane>(Vector3(0, -2.0, 0), Vector3(0,1,0), mirror);
    auto ceiling = std::make_shared<Plane>(Vector3(0, 3.0, 0), Vector3(0,-1,0), mirror);
    auto back = std::make_shared<Plane>(Vector3(0, 0, -8.0), Vector3(0,0,1), mirror);
    auto left = std::make_shared<Plane>(Vector3(-4.0, 0, 0), Vector3(1,0,0), mirror);
    auto right = std::make_shared<Plane>(Vector3(4.0, 0, 0), Vector3(-1,0,0), mirror);

    auto goldSphere = std::make_shared<Sphere>(Vector3(0.0, 0.0, -4.5), 1.2, goldRich);

    scene.addFigure(floor);
    scene.addFigure(ceiling);
    scene.addFigure(back);
    scene.addFigure(left);
    scene.addFigure(right);
    scene.addFigure(goldSphere);

    Light top("top", Vector3(0, 5.0, -4.0), 2.5, Vector3(1,1,1));
    Light fill("fill", Vector3(2.0, 1.0, -3.0), 0.8, Vector3(1,0.9,0.7));
    scene.addLight(top);
    scene.addLight(fill);
}