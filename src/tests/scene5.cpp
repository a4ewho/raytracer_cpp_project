#include "Scene.h"
#include "figures/Sphere.h"
#include "figures/Plane.h"
#include "Materials/material_library.h"
#include "Light.h"
#include <memory>

void setupScene5(Scene& scene) {
    scene.setBackgroundColor(Vector3(0.9, 0.9, 0.9));

    Material redMat("red_mat", Vector3(0.9, 0.2, 0.2), 0.2, 0.8, 0.1, 32, 0.0);
    Material blueMat("blue_mat", Vector3(0.2, 0.3, 0.9), 0.2, 0.8, 0.1, 32, 0.0);
    Material greenMat("green_mat", Vector3(0.2, 0.8, 0.2), 0.2, 0.8, 0.1, 32, 0.0);
    Material yellowMat("yellow_mat", Vector3(0.9, 0.9, 0.2), 0.2, 0.8, 0.1, 32, 0.0);
    Material purpleMat("purple_mat", Vector3(0.8, 0.2, 0.8), 0.2, 0.8, 0.1, 32, 0.0);

    auto sphereRed   = std::make_shared<Sphere>(Vector3(-2.0, -0.5, -4.0), 0.8, redMat);
    auto sphereBlue  = std::make_shared<Sphere>(Vector3(2.0, -0.3, -4.5), 0.9, blueMat);
    auto sphereGreen = std::make_shared<Sphere>(Vector3(-1.0, -0.2, -6.0), 0.7, greenMat);
    auto sphereYellow= std::make_shared<Sphere>(Vector3(1.0, -0.4, -6.5), 0.8, yellowMat);
    auto spherePurple= std::make_shared<Sphere>(Vector3(0.0, 0.0, -8.0), 0.9, purpleMat);

    auto ground = std::make_shared<Plane>(Vector3(0, -1.2, 0), Vector3(0,1,0), MaterialLibrary::get("plastic"));

    scene.addFigure(sphereRed);
    scene.addFigure(sphereBlue);
    scene.addFigure(sphereGreen);
    scene.addFigure(sphereYellow);
    scene.addFigure(spherePurple);
    scene.addFigure(ground);

    Light mainLight("main", Vector3(0, 6.0, -2.0), 2.2, Vector3(1,1,1));
    Light backRim("backRim", Vector3(0, 2.0, -9.0), 1.0, Vector3(0.9,0.8,1.0));
    scene.addLight(mainLight);
    scene.addLight(backRim);
}