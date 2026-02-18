#ifndef SEGMENT3DSOLVER_H
#define SEGMENT3DSOLVER_H
#include <optional>

#include "core/Segment3D.h"


class Segment3DSolver {
public:
    static std::optional<Vector3D> get_intersect_vector(const Segment3D&, const Segment3D&);
};



#endif //SEGMENT3DSOLVER_H
