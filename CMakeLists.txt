cmake_minimum_required(VERSION 3.16)
project(Raytracer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем все .cpp файлы
add_executable(raytracer
        src/main.cpp
        src/core/Vector3.cpp
        src/core/Ray.cpp
)

target_include_directories(raytracer PRIVATE src)