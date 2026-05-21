#include "material_library.h"
#include <stdexcept>

std::map<std::string, std::shared_ptr<Material>> MaterialLibrary::m_materials = MaterialLibrary::createMaterials();

std::map<std::string, std::shared_ptr<Material>> MaterialLibrary::createMaterials() {
    std::map<std::string, std::shared_ptr<Material>> mats;

    // === Диэлектрики (обычные материалы с diffuse + specular) ===
    mats["plastic"] = std::make_shared<Material>("plastic", Vector3(1.0, 0.2, 0.2), 0.1, 0.6, 0.3, 32, 0.0);
    mats["rubber"]  = std::make_shared<Material>("rubber",  Vector3(0.1, 0.1, 0.1), 0.1, 0.7, 0.1, 8, 0.0);
    mats["wood"]    = std::make_shared<Material>("wood",    Vector3(0.55, 0.27, 0.07), 0.15, 0.65, 0.15, 12, 0.0);

    // === Зеркало (только specular + полное отражение) ===
    mats["mirror"]  = std::make_shared<Material>("mirror",  Vector3(1.0, 1.0, 1.0), 0.0, 0.0, 1.0, 300, 1.0);

    // === Металлы (ka=0, kd=0, цвет задаёт F0) ===
    mats["aluminum"] = std::make_shared<Material>("aluminum", Vector3(0.91, 0.92, 0.92), 0.0, 0.0, 0.95, 120, 0.95);
    mats["gold"]     = std::make_shared<Material>("gold",     Vector3(1.00, 0.86, 0.57), 0.0, 0.0, 0.98, 80, 0.98);
    mats["steel"]    = std::make_shared<Material>("steel",    Vector3(0.56, 0.57, 0.58), 0.0, 0.0, 0.90, 250, 0.90);
    mats["copper"]   = std::make_shared<Material>("copper",   Vector3(0.95, 0.60, 0.40), 0.0, 0.0, 0.95, 60, 0.95);

    // === Стекло (с учётом преломления) ===
    mats["glass"] = std::make_shared<Material>("glass", Vector3(0.95, 0.97, 1.0), 0.05, 0.05, 0.95, 256, 0.7);

    return mats;
}

const Material& MaterialLibrary::get(const std::string& name) {
    auto it = m_materials.find(name);
    if (it == m_materials.end()) {
        throw std::runtime_error("Unknown material: " + name);
    }
    return *(it->second);
}

std::vector<std::string> MaterialLibrary::listAvailable() {
    std::vector<std::string> names;
    for (auto& pair : m_materials) {
        names.push_back(pair.first);
    }
    return names;
}