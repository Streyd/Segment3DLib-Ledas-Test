#ifndef VECTOR3D_H
#define VECTOR3D_H


class Vector3D {
    double _x = 0;
    double _y = 0;
    double _z = 0;



public:

    Vector3D() = default;

    Vector3D(double x, double y, double z): _x(x), _y(y), _z(z){}

    bool operator==(const Vector3D & vector_3d) const = default;

    [[nodiscard]] double x() const {
        return _x;
    }

    [[nodiscard]] double y() const {
        return _y;
    }

    [[nodiscard]] double z() const {
        return _z;
    }

    [[nodiscard]] double get_squared_len() const;

    [[nodiscard]] double get_len() const;

    [[nodiscard]] bool is_zero() const;

    [[nodiscard]] Vector3D cross(const Vector3D&) const;
    [[nodiscard]] double dot(const Vector3D&) const;

    Vector3D & operator+=(const Vector3D&);
    friend Vector3D operator+(Vector3D, const Vector3D&);

    Vector3D & operator-=(const Vector3D&);
    friend Vector3D operator-(Vector3D, const Vector3D&);

    Vector3D & operator*=(double);
    friend Vector3D operator*(Vector3D, double);

    Vector3D & operator*=(const Vector3D&);
    friend Vector3D operator*(Vector3D, const Vector3D&);

    Vector3D & operator/=(const Vector3D&);
    friend Vector3D operator/(Vector3D, const Vector3D&);

};



#endif //VECTOR3D_H
