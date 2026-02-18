#ifndef SEGMENT3D_H
#define SEGMENT3D_H
#include "Vector3D.h"


class Segment3D {
    Vector3D _start;
    Vector3D _end;

public:

    Segment3D() = default;

    Segment3D(const Vector3D & v1, const Vector3D & v2): _start(v1), _end(v2) {};

    [[nodiscard]] Vector3D start() const {
        return _start;
    }

    [[nodiscard]] Vector3D end() const {
        return _end;
    }

    [[nodiscard]] double get_squared_len() const;

    [[nodiscard]] double get_len() const;

    [[nodiscard]] bool is_zero() const;
};



#endif //SEGMENT3D_H
