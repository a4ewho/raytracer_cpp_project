#include "Scene.h"
#include "figures/Sphere.h"
#include "figures/Plane.h"
#include "Materials/material_library.h"
#include "Light.h"
#include <memory>

void setupScene2(Scene& scene) {
    scene.setBackgroundColor(Vector3(0.1, 0.1, 0.15));

    const Material& aluminum = MaterialLibrary::get("aluminum");
    const Material& steel    = MaterialLibrary::get("steel");
    const Material& mirror   = MaterialLibrary::get("mirror");

    Material goldMat("gold_modified", Vector3(1.0, 0.8, 0.4), 0.1, 0.5, 0.6, 100, 0.4);

    auto sphereAlu  = std::make_shared<Sphere>(Vector3(-1.2, -0.2, -4.5), 0.8, aluminum);
    auto sphereSteel= std::make_shared<Sphere>(Vector3(1.3, -0.3, -5.0), 0.9, steel);
    auto sphereGold = std::make_shared<Sphere>(Vector3(0.0, 0.0, -6.0), 0.7, goldMat);
    auto mirrorPlane = std::make_shared<Plane>(Vector3(0, -1.2, 0), Vector3(0, 1, 0), mirror);

    scene.addFigure(sphereAlu);
    scene.addFigure(sphereSteel);
    scene.addFigure(sphereGold);
    scene.addFigure(mirrorPlane);

    Light key("key", Vector3(4.0, 5.0, -3.0), 2.0, Vector3(1,1,1));
    Light back("back", Vector3(-2.0, 4.0, -7.0), 1.2, Vector3(0.8,0.9,1.0));
    scene.addLight(key);
    scene.addLight(back);
}