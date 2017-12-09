//
// Created by Arnaud Pannatier on 28.11.17.
//

#include <cmath>
#include "Vector.h"

Vector::Vector (vector<double> v) {
    dim = Dimension(1,v.size());
    values = vector<vector<double>>(1,v);
    Transpose();

}
Vector::Vector (initializer_list<double> list) {
    values = vector2D();
        for(auto l : list){
            values.push_back(vector<double>(l));
        }
        dim = Dimension(values.size(), 1);
}

Vector::Vector (const Matrix & m) {
    if(m.size().cols != 1){
        throw "the dimension of the matrix does not corresponds to a vector";
    }else{
        dim = m.size();
        values = m.getValues();
    }
}

double Vector::norm () const {
    double norm = 0.0;

    for(size_t i = 0; i < len(); i++){
        norm += (*this)(i)*(*this)(i);
    }
    return sqrt(norm);
}

size_t Vector::len () const {
    return dim.lines;
}

const double &Vector::operator() (size_t i) const {
    return (*this)[i][0];
}

double Vector::dot (const Vector &v) const {
    return ((this->T())*v)(0,0);
}

double &Vector::operator() (size_t i) {
    return values[i][0];
}




