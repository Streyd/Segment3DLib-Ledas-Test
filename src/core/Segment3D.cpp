#include "core/Segment3D.h"
#include "utils/Constants.h"


double Segment3D::get_squared_len() const {
    return (_end - _start).get_squared_len();
}


double Segment3D::get_len() const {
    return (_end - _start).get_len();
}

bool Segment3D::is_zero() const {
    return (_start - _end).get_squared_len() < constants::SQUARED_EPSILON;
}


