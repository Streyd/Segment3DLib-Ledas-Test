#include "core/Vector3D.h"
#include "utils/Constants.h"
#include <cmath>


Vector3D& Vector3D::operator+=(const Vector3D& other) {
    _x += other._x;
    _y += other._y;
    _z += other._z;
    return *this;
}

Vector3D operator+(Vector3D left, const Vector3D &right) {
    left += right;
    return left;
}


Vector3D& Vector3D::operator-=(const Vector3D& other) {
    _x -= other._x;
    _y -= other._y;
    _z -= other._z;
    return *this;
}

Vector3D operator-(Vector3D left, const Vector3D &right) {
    left -= right;
    return left;
}

Vector3D& Vector3D::operator*=(double k) {
    _x *= k;
    _y *= k;
    _z *= k;
    return *this;
}

Vector3D operator*(Vector3D left, double right) {
    left *= right;
    return left;
}

Vector3D &Vector3D::operator*=(const Vector3D & other) {
    _x *= other._x;
    _y *= other._y;
    _z *= other._z;
    return *this;
}

Vector3D operator*(Vector3D left, const Vector3D & right) {
    left *= right;
    return left;
}

Vector3D &Vector3D::operator/=(const Vector3D & other) {
    _x /= other._x;
    _y /= other._y;
    _z /= other._z;
    return *this;
}

Vector3D operator/(Vector3D left, const Vector3D & right) {
    left /= right;
    return left;
}

double Vector3D::get_squared_len() const {
    return _x * _x + _y * _y + _z * _z;
}

double Vector3D::get_len() const {
    return sqrt(get_squared_len());
}


bool Vector3D::is_zero() const {
    return this->get_squared_len() < constants::SQUARED_EPSILON;
}

Vector3D Vector3D::cross(const Vector3D& other) const {
    return Vector3D{
                    _y * other._z - _z * other._y,
                    _z * other._x - _x * other._z,
                    _x * other._y - _y * other._x,
                   };
}

double Vector3D::dot(const Vector3D& other) const {
    return _x * other._x + _y * other._y + _z * other._z;
}






