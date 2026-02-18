#include "solvers/Segment3DSolver.h"
#include "solvers/Line3DSolver.h"
#include "utils/Constants.h"


std::optional<Vector3D> Segment3DSolver::get_intersect_vector(const Segment3D& a, const Segment3D& b) {
    const Line3D l1{a.start(), a.end() - a.start()};
    const Line3D l2{b.start(), b.end() - b.start()};

    if (const std::optional<Vector3D> line_intersect_vector = Line3DSolver::get_intersect_vector(l1, l2)) {
        const double t = *l1.get_param(*line_intersect_vector);
        const double s = *l2.get_param(*line_intersect_vector);
        if (t >= -constants::EPSILON && t <= 1 + constants::EPSILON &&
            s >= -constants::EPSILON && s <= 1 + constants::EPSILON) {
            return line_intersect_vector;
    }
    }

    return std::nullopt;
}
