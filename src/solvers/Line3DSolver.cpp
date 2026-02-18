#include "solvers/Line3DSolver.h"

std::optional<Segment3D> Line3DSolver::get_crossing_segment(const Line3D &a, const Line3D &b) {

    if (a.is_parallel(b))
        return std::nullopt;

    const Vector3D n = a.k().cross(b.k());
    const double det = n.get_squared_len();

    const Vector3D r = b.p() - a.p();

    const double t = r.cross(b.k()).dot(n) / det;
    const double s = r.cross(a.k()).dot(n) / det;

    const Vector3D v1 = a.get_point(t);
    const Vector3D v2 = b.get_point(s);

    return Segment3D{v1, v2};
}


std::optional<Vector3D> Line3DSolver::get_intersect_vector(const Line3D &a, const Line3D &b)
{
    const std::optional<Segment3D> crossing_segment = get_crossing_segment(a, b);
    return crossing_segment && crossing_segment->is_zero() ? std::optional{crossing_segment->start()} : std::nullopt;
}
