#ifndef LINESOLVER_H
#define LINESOLVER_H
#include <optional>

#include "core/Line3D.h"
#include "core/Segment3D.h"


class Line3DSolver {
    public:
        static std::optional<Segment3D> get_crossing_segment(const Line3D& a, const Line3D& b);
        static std::optional<Vector3D> get_intersect_vector(const Line3D& a, const Line3D& b);
};



#endif //LINESOLVER_H
