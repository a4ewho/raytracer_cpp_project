#include "Vector3.h"

// конструктор
Vector3::Vector3() : data{0.0, 0.0, 0.0} {}

Vector3::Vector3(double x, double y, double z) : data{x, y, z} {}

// унарный минус
Vector3 Vector3::operator-() const {
    return Vector3(-data[0], -data[1], -data[2]);
}

// операторы присваивания
Vector3& Vector3::operator+=(const Vector3& other) {
    data[0] += other.data[0];
    data[1] += other.data[1];
    data[2] += other.data[2];
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& other) {
    data[0] -= other.data[0];
    data[1] -= other.data[1];
    data[2] -= other.data[2];
    return *this;
}

Vector3& Vector3::operator*=(double scalar) {
    data[0] *= scalar;
    data[1] *= scalar;
    data[2] *= scalar;
    return *this;
}

Vector3& Vector3::operator/=(double scalar) {
    data[0] /= scalar;
    data[1] /= scalar;
    data[2] /= scalar;
    return *this;
}

// длина
double Vector3::lengthSquared() const {
    return data[0] * data[0] + data[1] * data[1] + data[2] * data[2];
}

double Vector3::length() const {
    return std::sqrt(lengthSquared());
}

// нормализация
Vector3 Vector3::normalized() const {
    double len = length();
    if (len < 1e-8) {
        return Vector3(0, 0, 0);
    }
    return Vector3(data[0] / len, data[1] / len, data[2] / len);
}

// глобальные операторы
Vector3 operator+(const Vector3& a, const Vector3& b) {
    Vector3 result = a;
    result += b;
    return result;
}

Vector3 operator-(const Vector3& a, const Vector3& b) {
    Vector3 result = a;
    result -= b;
    return result;
}

Vector3 operator*(const Vector3& v, double scalar) {
    Vector3 result = v;
    result *= scalar;
    return result;
}

Vector3 operator*(double scalar, const Vector3& v) {
    return v * scalar;
}

Vector3 operator*(const Vector3& a, const Vector3& b) {
    return Vector3(a.x() * b.x(), a.y() * b.y(), a.z() * b.z());
}

Vector3 operator/(const Vector3& v, double scalar) {
    return v * (1.0 / scalar);
}

// скалярное произведение
double dot(const Vector3& a, const Vector3& b) {
    return a.x() * b.x() + a.y() * b.y() + a.z() * b.z();
}

// векторное произведение
Vector3 cross(const Vector3& a, const Vector3& b) {
    return Vector3(
        a.y() * b.z() - a.z() * b.y(),
        a.z() * b.x() - a.x() * b.z(),
        a.x() * b.y() - a.y() * b.x()
    );
}

std::ostream& operator<<(std::ostream& os, const Vector3& v) {
    os << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
    return os;
}