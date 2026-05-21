#include <iostream>
#include "core/Vector3.h"
#include "core/Ray.h"
#include "figures/Sphere.h"
#include "figures/Plane.h"
#include "Material.h"

int main() {
    std::cout << "========== SPHERE TESTS ==========" << std::endl;

    // Создаём сферу с центром в (0,0,-5) и радиусом 1
    Sphere sphere(Vector3(0, 0, -5), 1.0);

    std::cout << "Sphere center: " << sphere.center() << std::endl;
    std::cout << "Sphere radius: " << sphere.radius() << std::endl;
    std::cout << "Sphere name: " << sphere.name() << std::endl;

    // Тест 1: Луч, который попадает в сферу
    Ray ray1(Vector3(0, 0, 0), Vector3(0, 0, -1));
    auto hit1 = sphere.hit(ray1);

    if (hit1) {
        std::cout << "\nRay (0,0,0) -> (0,0,-1) HITS the sphere!" << std::endl;
        std::cout << "  t = " << hit1->t << std::endl;
        std::cout << "  point = " << hit1->point << std::endl;
        std::cout << "  normal = " << hit1->normal << std::endl;
    } else {
        std::cout << "\nRay (0,0,0) -> (0,0,-1) MISSES the sphere" << std::endl;
    }

    // Тест 2: Луч, который проходит мимо сферы
    Ray ray2(Vector3(0, 0, 0), Vector3(2, 0, -1));
    auto hit2 = sphere.hit(ray2);

    if (hit2) {
        std::cout << "\nRay (0,0,0) -> (2,0,-1) HITS the sphere!" << std::endl;
        std::cout << "  t = " << hit2->t << std::endl;
    } else {
        std::cout << "\nRay (0,0,0) -> (2,0,-1) MISSES the sphere" << std::endl;
    }

    // Тест 3: Луч, который начинается внутри сферы
    Ray ray3(Vector3(0, 0, -4.5), Vector3(0, 0, -1));
    auto hit3 = sphere.hit(ray3);

    if (hit3) {
        std::cout << "\nRay from INSIDE: t = " << hit3->t << std::endl;
        std::cout << "  point = " << hit3->point << std::endl;
        std::cout << "  normal = " << hit3->normal << std::endl;  // ← добавить!
    } else {
        std::cout << "\nRay from INSIDE: no hit (should hit back face)" << std::endl;
    }


    std::cout << "\n========== PLANE TESTS ==========" << std::endl;

    // Плоскость на y = -1, нормаль вверх
    Plane plane(Vector3(0, -1, 0), Vector3(0, 1, 0));

    std::cout << "Plane point: " << plane.point() << std::endl;
    std::cout << "Plane normal: " << plane.normal() << std::endl;

    // Тест 1: Луч сверху вниз (должен попасть)
    Ray ray4(Vector3(0, 0, 0), Vector3(0, -1, 0));
    auto hit4 = plane.hit(ray4);

    if (hit4) {
        std::cout << "\nRay (0,0,0) -> (0,-1,0) HITS the plane!" << std::endl;
        std::cout << "  t = " << hit4->t << std::endl;
        std::cout << "  point = " << hit4->point << std::endl;
        std::cout << "  normal = " << hit4->normal << std::endl;
    }

    // Тест 2: Луч снизу вверх (должен попасть с другой стороны)
    Ray ray5(Vector3(0, -2, 0), Vector3(0, 1, 0));
    auto hit5 = plane.hit(ray5);

    if (hit5) {
        std::cout << "\nRay (0,-2,0) -> (0,1,0) HITS the plane!" << std::endl;
        std::cout << "  t = " << hit5->t << std::endl;
        std::cout << "  point = " << hit5->point << std::endl;
        std::cout << "  normal = " << hit5->normal << std::endl;
    }

    // Тест 3: Луч параллельно плоскости (промах)
    Ray ray6(Vector3(0, 0, 0), Vector3(1, 0, 0));
    auto hit6 = plane.hit(ray6);

    if (!hit6) {
        std::cout << "\nRay (0,0,0) -> (1,0,0) MISSES (parallel)" << std::endl;
    }


    std::cout << "\n========== MATERIAL TESTS ==========" << std::endl;

    // Тест 1: Конструктор по умолчанию
    Material defaultMat;
    std::cout << "Default material:" << std::endl;
    std::cout << "  name: " << defaultMat.name() << std::endl;
    std::cout << "  color: " << defaultMat.color() << std::endl;
    std::cout << "  Ka: " << defaultMat.ka() << std::endl;
    std::cout << "  Kd: " << defaultMat.kd() << std::endl;
    std::cout << "  Ks: " << defaultMat.ks() << std::endl;
    std::cout << "  shininess: " << defaultMat.shininess() << std::endl;

    // Тест 2: Пользовательский материал (красный)
    Material redMat("red", Vector3(1.0, 0.2, 0.2), 0.2, 0.7, 0.5, 32);
    std::cout << "\nRed material:" << std::endl;
    std::cout << "  name: " << redMat.name() << std::endl;
    std::cout << "  color: " << redMat.color() << std::endl;
    std::cout << "  Ka: " << redMat.ka() << std::endl;
    std::cout << "  Kd: " << redMat.kd() << std::endl;
    std::cout << "  Ks: " << redMat.ks() << std::endl;
    std::cout << "  shininess: " << redMat.shininess() << std::endl;

    // Тест 3: Материал как металл
    Material metalMat("metal", Vector3(0.9, 0.9, 0.9), 0.2, 0.4, 0.9, 128);
    std::cout << "\nMetal material:" << std::endl;
    std::cout << "  name: " << metalMat.name() << std::endl;
    std::cout << "  color: " << metalMat.color() << std::endl;
    std::cout << "  Ka: " << metalMat.ka() << std::endl;
    std::cout << "  Kd: " << metalMat.kd() << std::endl;
    std::cout << "  Ks: " << metalMat.ks() << std::endl;
    std::cout << "  shininess: " << metalMat.shininess() << std::endl;

    // Тест 4: Матовый материал
    Material matteMat("matte", Vector3(0.8, 0.8, 0.8), 0.3, 0.9, 0.1, 8);
    std::cout << "\nMatte material:" << std::endl;
    std::cout << "  name: " << matteMat.name() << std::endl;
    std::cout << "  color: " << matteMat.color() << std::endl;
    std::cout << "  Ka: " << matteMat.ka() << std::endl;
    std::cout << "  Kd: " << matteMat.kd() << std::endl;
    std::cout << "  Ks: " << matteMat.ks() << std::endl;
    std::cout << "  shininess: " << matteMat.shininess() << std::endl;


    std::cout << "\n========== SPHERE WITH MATERIAL TESTS ==========" << std::endl;

    // Сфера с материалом по умолчанию
    Sphere defaultSphere(Vector3(0, 0, -5), 1.0);
    std::cout << "Sphere with default material:" << std::endl;
    std::cout << "  material name: " << defaultSphere.material().name() << std::endl;
    std::cout << "  material color: " << defaultSphere.material().color() << std::endl;

    // Сфера с красным материалом
    Sphere redSphere(Vector3(1, 0, -4), 0.8, redMat);
    std::cout << "\nSphere with red material:" << std::endl;
    std::cout << "  material name: " << redSphere.material().name() << std::endl;
    std::cout << "  material color: " << redSphere.material().color() << std::endl;

    // Сфера с металлическим материалом
    Sphere metalSphere(Vector3(-1, 0, -4.5), 0.9, metalMat);
    std::cout << "\nSphere with metal material:" << std::endl;
    std::cout << "  material name: " << metalSphere.material().name() << std::endl;
    std::cout << "  material color: " << metalSphere.material().color() << std::endl;


    std::cout << "\n========== PLANE WITH MATERIAL TESTS ==========" << std::endl;

    // Плоскость с матовым материалом
    Plane mattePlane(Vector3(0, -1, 0), Vector3(0, 1, 0), matteMat);
    std::cout << "Plane with matte material:" << std::endl;
    std::cout << "  material name: " << mattePlane.material().name() << std::endl;
    std::cout << "  material color: " << mattePlane.material().color() << std::endl;
    std::cout << "  Ka: " << mattePlane.material().ka() << std::endl;
    std::cout << "  Kd: " << mattePlane.material().kd() << std::endl;
    std::cout << "  Ks: " << mattePlane.material().ks() << std::endl;

    return 0;
}