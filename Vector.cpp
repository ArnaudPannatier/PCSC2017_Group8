//
// Created by Arnaud Pannatier on 28.11.17.
//

#include "Vector.h"

Vector::Vector (vector<double> v) {
    dim = Dimension(1, v.size());
    values = vector<vector<double>>(1,v);
}

size_t Vector::size () const {
    return dim.cols;
}
