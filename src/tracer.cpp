#include "Tracer.h"
#include <cmath>
#include <algorithm>
#include <limits>

Tracer::Tracer(const Camera& camera, const Scene& scene)
    : m_camera(camera), m_scene(scene) {}

void Tracer::render(std::vector<uint8_t>& output) const {
    int width = m_scene.width();
    int height = m_scene.height();
    output.resize(width * height * 3);
    
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Ray ray = m_camera.getRay(x, y);
            Vector3 color = traceRay(ray, 0);
            // Гамма-коррекция 1/2.2
            color = Vector3(
                std::pow(color.x(), 1.0/2.2),
                std::pow(color.y(), 1.0/2.2),
                std::pow(color.z(), 1.0/2.2)
            );
            // clamp и преобразование в 0..255
            int idx = (y * width + x) * 3;
            output[idx + 0] = static_cast<uint8_t>(std::min(255.0, std::max(0.0, color.x() * 255.0)));
            output[idx + 1] = static_cast<uint8_t>(std::min(255.0, std::max(0.0, color.y() * 255.0)));
            output[idx + 2] = static_cast<uint8_t>(std::min(255.0, std::max(0.0, color.z() * 255.0)));
        }
    }
}

std::optional<std::pair<const Figure*, HitRecord>> Tracer::findClosest(const Ray& ray) const {
    const Figure* closestFigure = nullptr;
    HitRecord closestHit;
    double closestT = std::numeric_limits<double>::max();
    
    for (const auto& figure : m_scene.figures()) {
        auto hit = figure->hit(ray);
        if (hit.has_value() && hit->t > 1e-6 && hit->t < closestT) {
            closestT = hit->t;
            closestFigure = figure.get();
            closestHit = hit.value();
        }
    }
    
    if (closestFigure)
        return std::make_pair(closestFigure, closestHit);
    else
        return std::nullopt;
}

bool Tracer::isInShadow(const Vector3& point, const Light& light) const {
    Vector3 toLight = light.position() - point;
    double distToLight = toLight.length();
    if (distToLight < OFFSET_EPSILON) return false;
    
    Vector3 dir = toLight / distToLight;
    Ray shadowRay(point + dir * OFFSET_EPSILON, dir);
    
    for (const auto& figure : m_scene.figures()) {
        auto hit = figure->hit(shadowRay);
        if (hit.has_value() && hit->t < distToLight - OFFSET_EPSILON)
            return true;
    }
    return false;
}

Vector3 Tracer::computeLocalLighting(const Figure* figure, const HitRecord& hit, const Vector3& viewDir) const {
    Material mat = figure->material();  // копия, но можно хранить по ссылке
    Vector3 color = mat.color();
    Vector3 ambient = mat.ka() * color;   // I_a * Ka * color
    
    Vector3 result = ambient;
    
    for (const auto& light : m_scene.lights()) {
        if (isInShadow(hit.point, light))
            continue;
        
        Vector3 L = (light.position() - hit.point).normalized();
        Vector3 N = hit.normal;
        double diff = std::max(0.0, dot(N, L));
        
        Vector3 V = viewDir;
        Vector3 R = (2.0 * dot(N, L) * N - L).normalized();
        double spec = std::pow(std::max(0.0, dot(R, V)), mat.shininess());
        
        Vector3 lightIntensity = light.color() * light.intensity();
        result = result + mat.kd() * color * diff * lightIntensity
               + mat.ks() * color * spec * lightIntensity;
    }
    return result;
}

Vector3 Tracer::traceRay(const Ray& ray, int depth) const {
    if (depth > MAX_DEPTH)
        return Vector3(0,0,0);
    
    auto hitPair = findClosest(ray);
    if (!hitPair.has_value())
        return getBackgroundColor(ray);
    
    const Figure* figure = hitPair->first;
    HitRecord hit = hitPair->second;
    Vector3 viewDir = -ray.direction().normalized();
    
    // Локальное освещение
    Vector3 color = computeLocalLighting(figure, hit, viewDir);
    
    // Отражение (если материал имеет reflection coefficient)
    // Отражение (если материал имеет reflection coefficient)
    double kr = figure->material().reflectionCoeff();
    if (kr > 0.0 && depth < MAX_DEPTH) {
        Vector3 reflectDir = ray.direction() - 2.0 * dot(ray.direction(), hit.normal) * hit.normal;
        reflectDir = reflectDir.normalized();
        Ray reflectRay(hit.point + hit.normal * OFFSET_EPSILON, reflectDir);
        Vector3 reflectColor = traceRay(reflectRay, depth + 1);
        // Умножаем на цвет материала, чтобы отражение было окрашенным (для золота, меди и т.д.)
        color = color + figure->material().color() * kr * reflectColor;
    }
    
    return color;
}

Vector3 Tracer::getBackgroundColor(const Ray& ray) const {
    // Используем цвет фона, установленный в сцене
    return m_scene.backgroundColor();
}