#include "Scene.h"
#include "Camera.h"
#include "Tracer.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Прототипы функций настройки сцен
void setupScene1(Scene& scene);
void setupScene2(Scene& scene);
void setupScene3(Scene& scene);
void setupScene4(Scene& scene);
void setupScene5(Scene& scene);

// Вспомогательная функция для рендеринга и сохранения
void renderAndSave(Scene& scene, const Camera& camera, const std::string& filename) {
    Tracer tracer(camera, scene);
    std::vector<uint8_t> image;
    tracer.render(image);

    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Не удалось создать файл: " << filename << std::endl;
        return;
    }
    out << "P3\n" << scene.width() << " " << scene.height() << "\n255\n";
    for (size_t i = 0; i < image.size(); i += 3) {
        out << static_cast<int>(image[i]) << " "
            << static_cast<int>(image[i+1]) << " "
            << static_cast<int>(image[i+2]) << "\n";
    }
    out.close();
    std::cout << "Сохранено: " << filename << std::endl;
}

int main() {
    const int width = 800;
    const int height = 600;

    // Общая камера для всех сцен (можно менять при необходимости)
    Camera camera(Vector3(0, 1.5, 4.0), Vector3(0, -0.5, -5.0), Vector3(0, 1, 0), 60, width, height);

    // Сцена 1 – классика
    {
        Scene scene(width, height);
        setupScene1(scene);
        renderAndSave(scene, camera, "scene1_classic.ppm");
    }

    // Сцена 2 – металлы
    {
        Scene scene(width, height);
        setupScene2(scene);
        renderAndSave(scene, camera, "scene2_metals.ppm");
    }

    // Сцена 3 – стёкла
    {
        Scene scene(width, height);
        setupScene3(scene);
        renderAndSave(scene, camera, "scene3_glasses.ppm");
    }

    // Сцена 4 – зеркальная комната
    {
        Scene scene(width, height);
        setupScene4(scene);
        renderAndSave(scene, camera, "scene4_mirror_room.ppm");
    }

    // Сцена 5 – абстракция (матовые шары)
    {
        Scene scene(width, height);
        setupScene5(scene);
        renderAndSave(scene, camera, "scene5_matte_balls.ppm");
    }

    std::cout << "Все 5 сцен отрендерены!" << std::endl;
    return 0;
}