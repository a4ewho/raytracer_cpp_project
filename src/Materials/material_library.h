#ifndef MATERIAL_LIBRARY_H
#define MATERIAL_LIBRARY_H

#include "Material.h"
#include <string>
#include <map>
#include <memory>

class MaterialLibrary {
public:
    // Возвращает материал по имени (константная ссылка)
    static const Material& get(const std::string& name);
    
    // Список доступных имён
    static std::vector<std::string> listAvailable();

private:
    // Инициализация предопределённых материалов
    static std::map<std::string, std::shared_ptr<Material>> createMaterials();
    
    static std::map<std::string, std::shared_ptr<Material>> m_materials;
};

#endif