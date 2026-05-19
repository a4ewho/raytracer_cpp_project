#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <cmath>
#include <iostream>

class Vector3 {
public:
    // конструктор
    Vector3();
    Vector3(double x, double y, double z);

    double x() const { return data[0]; }
    double y() const { return data[1]; }
    double z() const { return data[2]; }

    void setX(double value) { data[0] = value; }
    void setY(double value) { data[1] = value; }
    void setZ(double value) { data[2] = value; }

    // операторы
    Vector3 operator-() const;
    Vector3& operator+=(const Vector3& other);
    Vector3& operator-=(const Vector3& other);
    Vector3& operator*=(double scalar);
    Vector3& operator/=(double scalar);

    // длина
    double length() const;
    double lengthSquared() const;

    // нормализация
    Vector3 normalized() const;

    // доступ по индексу
    double operator[](int i) const { return data[i]; }
    double& operator[](int i) { return data[i]; }
    
private:
    double data[3];
};

// глобальные операторы
Vector3 operator+(const Vector3& a, const Vector3& b);
Vector3 operator-(const Vector3& a, const Vector3& b);
Vector3 operator*(const Vector3& v, double scalar);
Vector3 operator*(double scalar, const Vector3& v);
Vector3 operator/(const Vector3& v, double scalar);

// скалярное произведение
double dot(const Vector3& a, const Vector3& b);

// векторное произведение
Vector3 cross(const Vector3& a, const Vector3& b);

std::ostream& operator<<(std::ostream& os, const Vector3& v);

#endif // VECTOR3_HPP