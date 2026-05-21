#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <optional>
#include "../core/Vector3.h"
#include "../core/Ray.h"
#include "../Material.h"

// структура для хранения информации о пересечении
struct HitRecord {
    double t;           // расстояние от начала луча до точки пересечения
    Vector3 point;      // точка пересечения
    Vector3 normal;     // нормаль в точке пересечения
};

class Figure {
public:
    virtual ~Figure() = default;
    
    // проверка пересечения луча с фигурой
    // возвращает HitRecord если есть пересечение, иначе std::nullopt
    virtual std::optional<HitRecord> hit(const Ray& ray) const = 0;
    
    // получить имя фигуры (для отладки)
    virtual std::string name() const = 0;

    // материал
    virtual Material material() const = 0;
};

#endif // FIGURE_HPP