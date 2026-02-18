#include "core/Line3D.h"
#include "utils/Constants.h"


Vector3D Line3D::get_point(double t) const{
    return _p + _k * t;
}

std::optional<double> Line3D::get_param(const Vector3D& point) const {
    const Vector3D r = point - _p;

    if (!_k.cross(r).is_zero()) {
        return std::nullopt;
    }

    return r.dot(_k) / _k.get_squared_len();
}

bool Line3D::is_parallel(const Line3D & other) const {
    return _k.cross(other.k()).get_squared_len() < constants::SQUARED_EPSILON;
}




