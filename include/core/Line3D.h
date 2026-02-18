#ifndef LINE3D_H
#define LINE3D_H
#include <optional>

#include "Vector3D.h"


class Line3D {
    Vector3D _p;
    Vector3D _k;


public:

    Line3D() = default;

    Line3D(const Vector3D & p, const Vector3D & k): _p(p), _k(k) {};

    bool operator==(const Line3D & line_3d) const = default;

    [[nodiscard]] Vector3D p() const {
        return _p;
    }

    [[nodiscard]] Vector3D k() const {
        return _k;
    }

    [[nodiscard]] Vector3D get_point(double t) const;

    [[nodiscard]] std::optional<double> get_param(const Vector3D&) const;

    [[nodiscard]] bool is_parallel(const Line3D&) const;


};



#endif //LINE3D_H
