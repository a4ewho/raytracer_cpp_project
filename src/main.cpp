#include <iostream>
#include "core/Vector3.h"
#include "core/Ray.h"

int main() {
    // Тест Vector3 (уже есть)
    Vector3 a(1, 2, 3);
    Vector3 b(4, 5, 6);

    std::cout << "========== Vector3 TESTS ==========" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * 2 = " << a * 2 << std::endl;
    std::cout << "dot(a, b) = " << dot(a, b) << std::endl;
    std::cout << "cross(a, b) = " << cross(a, b) << std::endl;
    std::cout << "a.normalized() = " << a.normalized() << std::endl;
    std::cout << "a.length() = " << a.length() << std::endl;

    // Тест Ray
    std::cout << "\n========== RAY TESTS ==========" << std::endl;

    Ray ray(Vector3(0, 0, 0), Vector3(1, 0, 0));
    std::cout << "Ray origin: " << ray.origin() << std::endl;
    std::cout << "Ray direction: " << ray.direction() << std::endl;
    std::cout << "Ray at t=0: " << ray.at(0) << std::endl;
    std::cout << "Ray at t=1: " << ray.at(1) << std::endl;
    std::cout << "Ray at t=2.5: " << ray.at(2.5) << std::endl;

    Ray ray2(Vector3(1, 1, 1), Vector3(-1, -0.5, 2));
    std::cout << "\nRay2 at t=3: " << ray2.at(3) << std::endl;

    return 0;
}